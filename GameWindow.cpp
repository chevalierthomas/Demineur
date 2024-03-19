#include "GameWindow.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
#include <QTime>

int flagsPlaced;

GameWindow::GameWindow(QWidget *parent) : QDialog(parent), timer(new QTimer(this)) {
    ui.setupUi(this);
    connect(ui.change_difficulty, &QPushButton::clicked, this, &GameWindow::changeDifficulty);
    connect(ui.restart, &QPushButton::clicked, this, &GameWindow::restartGame);

    connect(timer, &QTimer::timeout, this, &GameWindow::updateTimer);
    // Ne démarrez pas le timer ici. Il sera démarré lors de la première action du joueur.
}

void GameWindow::setupGame(int width, int height, int mines) {


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
    mineGrid.resize(height); // Redimensionne le vecteur externe
    revealedGrid.clear();
    revealedGrid.resize(height); // Redimensionne le vecteur externe
    flagGrid.clear();
    flagGrid.resize(height); // Redimensionne le vecteur externe

    for (int i = 0; i < height; ++i) {
        mineGrid[i].resize(width); // Corrigé pour redimensionner sans le deuxième argument
        for (int j = 0; j < width; ++j) {
            mineGrid[i][j] = false; // Initialisez chaque élément à false séparément
        }
        revealedGrid[i].resize(width);
        for (int j = 0; j < width; ++j) {
            revealedGrid[i][j] = false; // Identique pour revealedGrid
        }
        flagGrid[i].resize(width);
        for (int j = 0; j < width; ++j) {
            flagGrid[i][j] = false; // Et pour flagGrid
        }
    }

    const int buttonSize = 40; // Taille des boutons

    for (int y = 0; y < height; ++y) {
        buttonGrid[y].resize(width);
        for (int x = 0; x < width; ++x) {
            QPushButton* button = new QPushButton();
            button->setFixedSize(buttonSize, buttonSize);
            button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            grid->addWidget(button, y, x);
            buttonGrid[y][x] = button;

            connect(button, &QPushButton::clicked, [this, x, y]() { this->reveal(x, y); });
            // Ajout de la fonctionnalité de marquage par un clic droit
            button->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(button, &QPushButton::customContextMenuRequested, [this, x, y](const QPoint &) { this->toggleFlag(x, y); });
        }
    }

    flagsPlaced = 0; // Réinitialisez le compteur de drapeaux
    updateFlagCount(); // Mettez à jour l'affichage du compteur de drapeaux
    gameStarted = false;

    generateMines(width, height, mines);
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
        startTime.start(); // Réinitialisez startTime pour commencer le suivi du temps
        timer->start(1000); // Assurez-vous que le timer se déclenche chaque seconde
        gameStarted = true; // Marquez le jeu comme ayant commencé
    }

    if (x < 0 || x >= gameWidth || y < 0 || y >= gameHeight || revealedGrid[y][x] || flagGrid[y][x]) return;

    revealedGrid[y][x] = true;
    QPushButton* button = buttonGrid[y][x];

    if (mineGrid[y][x]) {
        // Si le joueur clique sur une mine, on révèle la mine et on termine le jeu avec une défaite.
        button->setIcon(QIcon("./images/mine.png"));
        button->setIconSize(QSize(buttonSize - 10, buttonSize - 10));
        gameOver(false); // Arrête immédiatement le jeu et affiche le message de défaite.
        return;
    }

    // Si ce n'est pas une mine, continuez avec la logique existante.
    button->setEnabled(false);
    int adjacentMines = countAdjacentMines(x, y);
    if (adjacentMines > 0) {
        button->setText(QString::number(adjacentMines));
        QString color;
        switch (adjacentMines) {
        case 1: color = "blue"; break;
        case 2: color = "green"; break;
        case 3: color = "red"; break;
        // Ajoutez plus de cas selon le besoin
        default: color = "black"; break;
        }
        button->setStyleSheet("color: " + color + "; font-weight: bold; font-size: 16px;");
    } else {
        // Logique pour révéler les cases adjacentes si nécessaire.
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx != 0 || dy != 0) reveal(x + dx, y + dy);
            }
        }
    }
    checkWinCondition();
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
    // Désactive tous les boutons pour empêcher d'autres actions
    for (int y = 0; y < gameHeight; ++y) {
        for (int x = 0; x < gameWidth; ++x) {
            QPushButton* button = buttonGrid[y][x];
            button->setEnabled(false); // Désactive le bouton
            if (mineGrid[y][x] && !win) {
                // Affiche l'icône de la mine seulement si le joueur perd
                button->setIcon(QIcon("./images/mine.png"));
                button->setIconSize(QSize(buttonSize - 10, buttonSize - 10));
            }
        }
    }
    // Affiche un message de victoire ou de défaite
    QMessageBox::information(this, win ? "Victoire!" : "Défaite", win ? "Vous avez gagné!" : "Vous avez perdu!");
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
