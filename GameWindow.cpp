#include "GameWindow.h"
#include <QPushButton>
#include <QGridLayout>

GameWindow::GameWindow(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);
    // Configuration initiale ou connectez des slots ici si nécessaire
}

void GameWindow::setupGame(int width, int height, int mines) {
    // Exemple simple : nettoyez la grille précédente et créez une nouvelle
    auto *layout = new QGridLayout();
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            auto *button = new QPushButton(this);
            // Configurez le bouton, par exemple avec `connect()`
            layout->addWidget(button, row, col);
        }
    }
    ui.horizontalLayoutWidget->setLayout(layout);
    // Ajoutez ici la logique pour placer les mines et configurer le jeu
}
