#include "GameWindow.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
#include <QTime>
#include <QSoundEffect>
#include <iostream>
#include <QInputDialog>
#include <QLineEdit>


int flagsPlaced;
bool isFirst = true;

GameWindow::GameWindow(DifficultySelectionDialog* difficultyDialog, QWidget *parent)
    : QDialog(parent), m_difficultyDialog(difficultyDialog), timer(new QTimer(this)) {
    ui.setupUi(this);
    // Your existing initializations go here

    connect(ui.change_difficulty, &QPushButton::clicked, this, &GameWindow::changeDifficulty);
    connect(ui.restart, &QPushButton::clicked, this, &GameWindow::restartGame);
    connect(timer, &QTimer::timeout, this, &GameWindow::updateTimer);

    startGameSound.setSource(QUrl("qrc:/assets/click-start-game.wav"));
    clickSoundEffect.setSource(QUrl("qrc:/assets/discover-click.wav"));
    victorySoundEffect.setSource(QUrl("qrc:/assets/victory.wav"));
    defeatSoundEffect.setSource(QUrl("qrc:/assets/defeat.wav"));

    // Ensure the rest of your initializations are compatible with having a DifficultySelectionDialog instance
}


void GameWindow::setupGame(int width, int height, int mines) {
    if(isFirst == false){
        clearGame();
    }
    isFirst = false;

    gameFinished = false; // Prépare pour une nouvelle partie

    // Vérifie si le son est activé et joue le son de début de jeu si c'est le cas
    if (m_difficultyDialog->isSoundEnabled()) {
        startGameSound.play();
    }

    gameWidth = width;
    gameHeight = height;
    totalMines = mines;

    QGridLayout* grid = static_cast<QGridLayout*>(ui.gridMines->layout());
    qDeleteAll(grid->children());
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    buttonGrid.clear();
    buttonGrid.resize(height);
    mineGrid.clear();
    mineGrid.resize(height);
    revealedGrid.clear();
    revealedGrid.resize(height);
    flagGrid.clear();
    flagGrid.resize(height);

    for (int i = 0; i < height; ++i) {
        mineGrid[i].resize(width);
        revealedGrid[i].resize(width);
        flagGrid[i].resize(width);
        for (int j = 0; j < width; ++j) {
            mineGrid[i][j] = false;
            revealedGrid[i][j] = false;
            flagGrid[i][j] = false;
        }
    }

    const int buttonSize = 40; // Supposons que chaque bouton a une taille de 40x40.

    for (int y = 0; y < height; ++y) {
        buttonGrid[y].resize(width);
        for (int x = 0; x < width; ++x) {
            QPushButton* button = new QPushButton();
            button->setFixedSize(buttonSize, buttonSize);
            grid->addWidget(button, y, x);
            buttonGrid[y][x] = button;
            connect(button, &QPushButton::clicked, [this, x, y]() { this->reveal(x, y); });
            button->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(button, &QPushButton::customContextMenuRequested, [this, x, y](const QPoint &) { this->toggleFlag(x, y); });
        }
    }

    updateFlagCount();
    gameStarted = false;
    generateMines(width, height, mines);

    // Ajustement de la taille de la fenêtre
    int extraSpace = 100; // Ajustez cette valeur selon vos besoins d'UI
    this->setMinimumSize(width * buttonSize + extraSpace, height * buttonSize + extraSpace);
    this->adjustSize();
}


void GameWindow::generateMines(int width, int height, int mines) {
    while (mines > 0) {
        int x = QRandomGenerator::global()->bounded(width);
        int y = QRandomGenerator::global()->bounded(height);
        if (!mineGrid[y][x]) {
            mineGrid[y][x] = true;
            --mines;
        }
    }
}

void GameWindow::reveal(int x, int y) {

    if (!gameStarted) {
        startTime.start(); // Commence à suivre le temps dès la première action de l'utilisateur
        timer->start(1000); // Démarre le timer pour se déclencher chaque seconde
        gameStarted = true; // Marque le début du jeu
    }

    if (m_difficultyDialog->isSoundEnabled()) {
        clickSoundEffect.play();
    }


    if (x < 0 || x >= gameWidth || y < 0 || y >= gameHeight || revealedGrid[y][x] || flagGrid[y][x]) {
        return; // Vérifie les conditions de limite et si la case a déjà été révélée ou marquée d'un drapeau
    }

    revealedGrid[y][x] = true; // Marque la case comme révélée
    QPushButton* button = buttonGrid[y][x];

    if (mineGrid[y][x]) {
        // Le joueur a cliqué sur une mine
        button->setIcon(QIcon("./images/mine.png")); // Affiche une icône de mine
        button->setIconSize(QSize(buttonSize - 10, buttonSize - 10)); // Ajuste la taille de l'icône
        gameOver(false); // Termine le jeu avec une défaite
        return;
    }

    // Pas une mine, procède à la logique de révélation
    button->setEnabled(false); // Désactive le bouton pour empêcher d'autres clics

    int adjacentMines = countAdjacentMines(x, y); // Compte les mines adjacentes
    if (adjacentMines > 0) {
        // Affiche le nombre de mines adjacentes sur le bouton
        button->setText(QString::number(adjacentMines));
        QString color;
        // Sélectionne une couleur basée sur le nombre de mines adjacentes
        switch (adjacentMines) {
            case 1: color = "blue"; break;
            case 2: color = "green"; break;
            case 3: color = "red"; break;
            // Ajoutez d'autres couleurs au besoin
            default: color = "black"; break;
        }
        button->setStyleSheet("color: " + color + "; font-weight: bold; font-size: 16px;");
    } else {
        // Aucune mine adjacente, révèle récursivement les cases adjacentes
        button->setStyleSheet("background-color: #c06c84;"); // Modifie la couleur de fond pour les cases sûres
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx != 0 || dy != 0) reveal(x + dx, y + dy); // Révélation récursive
            }
        }
    }

    checkWinCondition(); // Vérifie si le joueur a gagné après chaque révélation
}

void GameWindow::toggleFlag(int x, int y) {
    if (revealedGrid[y][x] || x < 0 || x >= gameWidth || y < 0 || y >= gameHeight) {
        return;
    }

    QPushButton* button = buttonGrid[y][x];
    // Vérifie si on ajoute un drapeau et s'il reste des drapeaux à placer
    if (!flagGrid[y][x] && flagsPlaced < totalMines) {
        button->setIcon(QIcon("./images/flag.png"));
        button->setIconSize(QSize(buttonSize - 10, buttonSize - 10));
        flagGrid[y][x] = true;
        flagsPlaced++;
    }
    // Permet de retirer un drapeau même si le maximum est atteint
    else if (flagGrid[y][x]) {
        button->setIcon(QIcon());
        flagGrid[y][x] = false;
        flagsPlaced--;
    }
    updateFlagCount();
    checkWinCondition();
}

void GameWindow::updateFlagCount() {
    ui.flag_count->setText(QString("%1/%2").arg(flagsPlaced).arg(totalMines));
}

int GameWindow::countAdjacentMines(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < gameWidth && ny >= 0 && ny < gameHeight && mineGrid[ny][nx]) {
                ++count;
            }
        }
    }
    return count;
}

void GameWindow::checkWinCondition() {
    for (int y = 0; y < gameHeight; ++y) {
        for (int x = 0; x < gameWidth; ++x) {
            if (!mineGrid[y][x] && !revealedGrid[y][x]) return; // Si une case non-minée n'est pas révélée, le jeu continue
        }
    }
    // Si on arrive ici, toutes les cases non-minées ont été révélées
    gameOver(true);
}

void GameWindow::gameOver(bool win) {
    if (!gameFinished) {
        gameFinished = true; // Empêche de réentrer dans cette méthode


        timer->stop(); // Arrêtez le timer dès que le jeu se termine pour capturer le temps de jeu actuel.

        int elapsedSeconds = startTime.elapsed() / 1000;
        QTime timeElapsed = QTime(0, 0, 0, 0).addSecs(elapsedSeconds);

        // Désactivez tous les boutons pour empêcher d'autres interactions.
        for (int y = 0; y < gameHeight; ++y) {
            for (int x = 0; x < gameWidth; ++x) {
                QPushButton* button = buttonGrid[y][x];
                button->setEnabled(false);
                if (mineGrid[y][x] && !win) {
                    button->setIcon(QIcon("./images/mine.png"));
                    button->setIconSize(QSize(buttonSize - 10, buttonSize - 10));
                }
            }
        }

        if (win) {
            if (m_difficultyDialog->isSoundEnabled()) {
                victorySoundEffect.play();
            }

            // Demandez le nom du joueur avant d'enregistrer le score.
            bool ok;
            QString playerName = QInputDialog::getText(this, tr("Victoire!"),
                                                       tr("Entrez votre nom pour enregistrer le score :"),
                                                       QLineEdit::Normal, QString(), &ok);

            if (ok && !playerName.isEmpty()) {
                // Chargez les scores existants, ajoutez le nouveau score, puis sauvegardez tout.
                QList<ScoreRecord> scores = ScoreManager::instance().loadScores();
                ScoreRecord newScore{playerName, timeElapsed, gameWidth, gameHeight};
                scores.append(newScore);
                ScoreManager::instance().saveScores(scores);

                QMessageBox::information(this, tr("Victoire!"), tr("Félicitations ") + playerName + tr(", vous avez gagné !"));
            }
        } else {
            if (m_difficultyDialog->isSoundEnabled()) {
                defeatSoundEffect.play();
            }
            QMessageBox::information(this, tr("Défaite"), tr("Dommage, vous avez perdu. Essayez encore !"));
        }

        // Préparez pour un nouveau jeu ou la fermeture du jeu ici si nécessaire.
    }
}




void GameWindow::changeDifficulty() {
    emit changeDifficultyRequested(); // Notifiez le besoin de changer de difficulté
    // Vous pouvez ici fermer cette fenêtre ou cacher pour revenir à la sélection de difficulté
    this->close(); // Par exemple, fermer la fenêtre actuelle
}

void GameWindow::updateTimer() {
    if (!gameStarted) return; // Ne mettez à jour le temps que si le jeu a commencé

    int elapsedSeconds = startTime.elapsed() / 1000;
    QTime currentTime(0, 0, 0);
    currentTime = currentTime.addSecs(elapsedSeconds);
    ui.time->setText(currentTime.toString("HH:mm:ss"));
}

void GameWindow::restartGame() {
    setupGame(gameWidth, gameHeight, totalMines); // Utilisez les paramètres actuels pour redémarrer
}

void GameWindow::clearGame() {
    // Arrête le timer s'il est en cours d'exécution
    timer->stop();

    // Parcourt chaque rangée de la grille de boutons
    for (int y = 0; y < gameHeight; ++y) {
        // Parcourt chaque bouton dans la rangée
        for (int x = 0; x < gameWidth; ++x) {
            // Vérifie si le pointeur vers le bouton n'est pas null
            if (buttonGrid[y][x] != nullptr) {
                delete buttonGrid[y][x]; // Supprime l'objet QPushButton
                buttonGrid[y][x] = nullptr; // Réinitialise le pointeur à nullptr pour éviter l'utilisation après libération
            }
        }
    }


    // Efface les contenus des vecteurs pour réinitialiser la grille
    buttonGrid.clear();
    mineGrid.clear();
    revealedGrid.clear();
    flagGrid.clear();

    // Réinitialise les variables d'état du jeu
    flagsPlaced = 0;
    gameStarted = false;

    // Réinitialise l'affichage du temps
    ui.time->setText("");
}


