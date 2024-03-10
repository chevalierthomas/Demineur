#include <QApplication>
#include "DifficultySelectionDialog.h"
#include "CustomDifficultyDialog.h"
#include "GameWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GameWindow gameWindow;
    DifficultySelectionDialog* selectionDialog = new DifficultySelectionDialog();
    CustomDifficultyDialog* customDialog = nullptr; // Reste à nullptr jusqu'à la création

    QObject::connect(selectionDialog, &DifficultySelectionDialog::gameStartRequested,
                     [&](int width, int height, int mines) {
                         gameWindow.setupGame(width, height, mines);
                         gameWindow.show();
                     });

    QObject::connect(selectionDialog, &DifficultySelectionDialog::customizationRequested,
                     [&]() {
                         if (!customDialog) {
                             customDialog = new CustomDifficultyDialog();
                             // Déplacer la connexion à l'intérieur de ce bloc pour s'assurer que customDialog n'est pas nullptr
                             QObject::connect(customDialog, &QDialog::rejected, selectionDialog, &QDialog::show);
                             QObject::connect(customDialog, &QDialog::accepted, [&]() {
                                 int width = customDialog->getWidth();
                                 int height = customDialog->getHeight();
                                 int mines = customDialog->getMines();
                                 gameWindow.setupGame(width, height, mines);
                                 gameWindow.show();
                             });
                         }
                         selectionDialog->close(); // Ferme selectionDialog sans supprimer l'instance
                         customDialog->show(); // Affiche customDialog de manière non modale
                     });

    selectionDialog->show(); // Affiche le dialogue de sélection de manière non modale

    return app.exec();
}
