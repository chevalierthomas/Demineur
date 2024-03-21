#include "CustomDifficultyDialog.h"

CustomDifficultyDialog::CustomDifficultyDialog(QWidget *parent) : QDialog(parent) {

    ui.setupUi(this);

    // Définition des valeurs initiales pour les QSpinBox
    ui.largeur_input->setValue(10); // au lieu de setText
    ui.hauteur_input->setValue(10); // au lieu de setText
    ui.pourcentage_input->setValue(15); // au lieu de setText

    // Connexion des signaux et des slots
    connect(ui.validateButton, &QPushButton::clicked, this, &CustomDifficultyDialog::accept);
    connect(ui.cancelButton, &QPushButton::clicked, this, &CustomDifficultyDialog::reject);
}

int CustomDifficultyDialog::getWidth() const {
    return ui.largeur_input->value(); // au lieu de text().toInt()
}

int CustomDifficultyDialog::getHeight() const {
    return ui.hauteur_input->value(); // au lieu de text().toInt()
}

int CustomDifficultyDialog::getMines() const {
    return ui.pourcentage_input->value(); // au lieu de text().toInt()
}
