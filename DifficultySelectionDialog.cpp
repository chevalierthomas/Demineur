#include "DifficultySelectionDialog.h"
#include <QApplication>
#include <QSoundEffect> // Assurez-vous d'inclure QSoundEffect ici
#include <QMessageBox>


DifficultySelectionDialog::DifficultySelectionDialog(QWidget *parent) : QDialog(parent), soundEnabled(true) {
    ui.setupUi(this);

    recordsDialog = new RecordsDialog(this); // Ajoutez cette ligne

    connect(ui.showScoresButton, &QPushButton::clicked, this, &DifficultySelectionDialog::onShowScores); // Assurez-vous d'ajouter un QPushButton dans votre ui avec le nom "showScoresButton"

    connect(ui.schema_8_8, &QPushButton::clicked, this, &DifficultySelectionDialog::onStandardGameSelected);
    connect(ui.schema_16_16, &QPushButton::clicked, this, &DifficultySelectionDialog::onMediumGameSelected);
    connect(ui.schema_30_16, &QPushButton::clicked, this, &DifficultySelectionDialog::onHardGameSelected);
    connect(ui.schema_free, &QPushButton::clicked, this, &DifficultySelectionDialog::onCustomizationSelected);

    exitGameSoundEffect.setSource(QUrl("qrc:/assets/exit-game.wav"));

    connect(ui.exitButton, &QPushButton::clicked, this, &DifficultySelectionDialog::onExitRequested);

    connect(ui.soundButton, &QPushButton::clicked, this, &DifficultySelectionDialog::onToggleSound);

    updateSoundButtonIcon(); // Assurez-vous que l'icône initiale est correcte
}

void DifficultySelectionDialog::onShowScores() {
    recordsDialog->show(); // Affiche la fenêtre des scores
}

void DifficultySelectionDialog::onToggleSound() {
    soundEnabled = !soundEnabled; // Basculer l'état du son
    updateSoundButtonIcon(); // Mettre à jour l'icône du bouton

    // Ici, vous pouvez également activer/désactiver les effets sonores globalement si nécessaire
}

void DifficultySelectionDialog::updateSoundButtonIcon() {
    QSize iconSize(24, 24); // Vous pouvez ajuster la taille selon vos besoins
    ui.soundButton->setIconSize(iconSize);

    if (soundEnabled) {
        ui.soundButton->setIcon(QIcon(":/images/sound-on.png"));
    } else {
        ui.soundButton->setIcon(QIcon(":/images/sound-off.png"));
    }
}


void DifficultySelectionDialog::onStandardGameSelected() {
    emit gameStartRequested(8, 8, 10);
}

void DifficultySelectionDialog::onMediumGameSelected() {
    emit gameStartRequested(16, 16, 40); // Paramètres pour le niveau moyen
}

void DifficultySelectionDialog::onHardGameSelected() {
    emit gameStartRequested(30, 16, 99); // Paramètres pour le niveau difficile
}

void DifficultySelectionDialog::onCustomizationSelected() {

    emit customizationRequested();
    //accept(); // Ferme la boîte de dialogue
}

void DifficultySelectionDialog::onExitRequested() {
    if (soundEnabled){
        exitGameSoundEffect.play(); // Joue le son de sortie
    }

    // Afficher une boîte de dialogue de confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quitter", "Êtes-vous sûr de vouloir quitter ?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}
