#include <QApplication>
#include "DifficultySelectionDialog.h"
#include "CustomDifficultyDialog.h"
#include "GameWindow.h"
#include <iostream>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GameWindow gameWindow;
    DifficultySelectionDialog selectionDialog; // Utilisation d'une instance sur la pile
    CustomDifficultyDialog* customDialog = new CustomDifficultyDialog(&selectionDialog); // Création immédiate avec le parent correct

    QObject::connect(&selectionDialog, &DifficultySelectionDialog::gameStartRequested,
                     [&gameWindow](int width, int height, int mines) {
                         gameWindow.setupGame(width, height, mines);
                         gameWindow.show();
                     });

    // Simplification de la connexion pour l'affichage du dialogue personnalisé
    QObject::connect(&selectionDialog, &DifficultySelectionDialog::customizationRequested,
                     [customDialog, &selectionDialog]() {
                         selectionDialog.hide();
                         customDialog->show(); // Affiche directement le dialogue
                         std::cout << "Ceci est un message dans la console." << std::endl;

                     });

    QObject::connect(customDialog, &CustomDifficultyDialog::accepted,
                     [&gameWindow, customDialog]() {
                         int width = customDialog->getWidth();
                         int height = customDialog->getHeight();
                         int mines = customDialog->getMines();
                         gameWindow.setupGame(width, height, mines);
                         gameWindow.show();
                     });

    QObject::connect(&gameWindow, &GameWindow::changeDifficultyRequested,
                     [&gameWindow, &selectionDialog]() {
                         gameWindow.hide();
                         selectionDialog.show();
                     });

    selectionDialog.show(); // Affiche le dialogue de sélection

    return app.exec();
}
