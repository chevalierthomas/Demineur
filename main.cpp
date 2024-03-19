#include <QApplication>
#include "DifficultySelectionDialog.h"
#include "CustomDifficultyDialog.h"
#include "GameWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GameWindow gameWindow;
    DifficultySelectionDialog* selectionDialog = new DifficultySelectionDialog();
    CustomDifficultyDialog* customDialog = nullptr; // Initialisé à nullptr jusqu'à la création

    // Connexion pour démarrer le jeu avec des paramètres spécifiques
    QObject::connect(selectionDialog, &DifficultySelectionDialog::gameStartRequested,
                     [&](int width, int height, int mines) {
                         gameWindow.setupGame(width, height, mines);
                         gameWindow.show();
                     });

    // Connexion pour la demande de personnalisation
    QObject::connect(selectionDialog, &DifficultySelectionDialog::customizationRequested,
                     [&]() {
                         if (!customDialog) {
                             customDialog = new CustomDifficultyDialog(&gameWindow);
                             QObject::connect(customDialog, &CustomDifficultyDialog::accepted, [&]() {
                                 int width = customDialog->getWidth();
                                 int height = customDialog->getHeight();
                                 int mines = customDialog->getMines();
                                 gameWindow.setupGame(width, height, mines);
                                 gameWindow.show();
                             });
                         }
                         customDialog->show();
                     });

    // Connexion pour gérer le changement de difficulté demandé depuis GameWindow
    QObject::connect(&gameWindow, &GameWindow::changeDifficultyRequested, [&]() {
        gameWindow.hide();
        selectionDialog->show();
    });

    selectionDialog->show();

    return app.exec();
}
