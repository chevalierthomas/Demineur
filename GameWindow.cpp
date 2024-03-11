#include "GameWindow.h"
#include <QRandomGenerator>

GameWindow::GameWindow(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);
    // Vous pouvez ajouter ici la connexion des signaux pour les boutons Recommencer et Changer la difficulté
}

void GameWindow::setupGame(int width, int height, int mines) {
    // Obtient le QGridLayout déjà défini dans votre UI.
    QGridLayout* grid = static_cast<QGridLayout*>(ui.gridMines->layout());
    qDeleteAll(grid->children());
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    buttonGrid.clear();
    buttonGrid.resize(height);

    const int buttonSize = 40; // Définir selon les besoins

    for (int y = 0; y < height; ++y) {
        buttonGrid[y].resize(width);
        for (int x = 0; x < width; ++x) {
            QPushButton* button = new QPushButton();
            button->setFixedSize(buttonSize, buttonSize);

            // Réglez la politique de taille pour encourager la taille minimale
            button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

            grid->addWidget(button, y, x);
            buttonGrid[y][x] = button;

            connect(button, &QPushButton::clicked, [this, x, y]() {
                this->reveal(x, y);
            });
        }
    }

    // Ajoutez votre logique de placement des mines ici.
    generateMines(width, height, mines);
}


void GameWindow::generateMines(int width, int height, int mines) {
    // Votre logique pour placer les mines aléatoirement
    // Exemple simple (améliorez ceci pour éviter les doublons)
    while (mines > 0) {
        int x = QRandomGenerator::global()->bounded(width);
        int y = QRandomGenerator::global()->bounded(height);
        // Marquez cette case comme mine si votre structure de données le permet
        --mines;
    }
}

void GameWindow::reveal(int x, int y) {
    // Logique pour révéler la case et gérer les clics sur les mines
    // Ceci est un exemple. Adaptez selon votre implémentation
    QPushButton* button = buttonGrid[y][x];
    button->setText("*"); // Exemple pour marquer une révélation
    button->setEnabled(false); // Désactiver le bouton après révélation
}

