#include "DifficultySelectionDialog.h"
#include <QApplication>
#include <QSoundEffect> // Assurez-vous d'inclure QSoundEffect ici
#include <QMessageBox>


DifficultySelectionDialog::DifficultySelectionDialog(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);

    connect(ui.schema_8_8, &QPushButton::clicked, this, &DifficultySelectionDialog::onStandardGameSelected);
    connect(ui.schema_16_16, &QPushButton::clicked, this, &DifficultySelectionDialog::onMediumGameSelected);
    connect(ui.schema_30_16, &QPushButton::clicked, this, &DifficultySelectionDialog::onHardGameSelected);
    connect(ui.schema_free, &QPushButton::clicked, this, &DifficultySelectionDialog::onCustomizationSelected);

    exitGameSoundEffect.setSource(QUrl("qrc:/assets/exit-game.wav"));

    connect(ui.exitButton, &QPushButton::clicked, this, &DifficultySelectionDialog::onExitRequested);
}

void DifficultySelectionDialog::onStandardGameSelected() {
    emit gameStartRequested(8, 8, 10);
    accept();
}

void DifficultySelectionDialog::onMediumGameSelected() {
    emit gameStartRequested(16, 16, 40); // Paramètres pour le niveau moyen
    accept();
}

void DifficultySelectionDialog::onHardGameSelected() {
    emit gameStartRequested(30, 16, 99); // Paramètres pour le niveau difficile
    accept();
}

void DifficultySelectionDialog::onCustomizationSelected() {

    emit customizationRequested();
    //accept(); // Ferme la boîte de dialogue
}

void DifficultySelectionDialog::onExitRequested() {
    exitGameSoundEffect.play(); // Joue le son de sortie

    // Afficher une boîte de dialogue de confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quitter", "Êtes-vous sûr de vouloir quitter ?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}
