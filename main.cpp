#include <QApplication>
#include "DifficultySelectionDialog.h"
#include "CustomDifficultyDialog.h"
#include "GameWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Initialize selectionDialog before it's used.
    DifficultySelectionDialog* selectionDialog = new DifficultySelectionDialog(nullptr); // Assuming no parent

    // Now that selectionDialog is defined, pass it to the GameWindow constructor.
    GameWindow gameWindow(selectionDialog);

    // customDialog is correctly created with selectionDialog as its parent.
    CustomDifficultyDialog* customDialog = new CustomDifficultyDialog(selectionDialog);

    QObject::connect(customDialog, &CustomDifficultyDialog::cancelClicked, [selectionDialog]() {
        selectionDialog->show(); // Show the DifficultySelectionDialog again.
    });

    QObject::connect(selectionDialog, &DifficultySelectionDialog::gameStartRequested,
                     [&gameWindow, selectionDialog](int width, int height, int mines) {
                         selectionDialog->hide();
                         gameWindow.setupGame(width, height, mines);
                         gameWindow.show();
                     });

    QObject::connect(selectionDialog, &DifficultySelectionDialog::customizationRequested,
                     [customDialog, selectionDialog]() {
                         selectionDialog->hide();
                         customDialog->show(); // Show CustomDifficultyDialog directly.
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
                     [&gameWindow, selectionDialog]() {
                         gameWindow.hide();
                         selectionDialog->show(); // Return to DifficultySelectionDialog.
                     });

    selectionDialog->show(); // Initially show the DifficultySelectionDialog.

    return app.exec();
}
