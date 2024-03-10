#include "CustomDifficultyDialog.h"

CustomDifficultyDialog::CustomDifficultyDialog(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);

    ui.largeur_input->setText("10");
    ui.hauteur_input->setText("10");
    ui.pourcentage_input->setText("15");

    connect(ui.validateButton, &QPushButton::clicked, this, &CustomDifficultyDialog::accept);
    connect(ui.cancelButton, &QPushButton::clicked, this, &CustomDifficultyDialog::reject);
}

int CustomDifficultyDialog::getWidth() const {
    return ui.largeur_input->text().toInt();
}

int CustomDifficultyDialog::getHeight() const {
    return ui.hauteur_input->text().toInt();
}

int CustomDifficultyDialog::getMines() const {
    return ui.pourcentage_input->text().toInt();
}