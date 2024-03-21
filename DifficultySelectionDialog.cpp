#include "DifficultySelectionDialog.h"
#include <QApplication>

#include <iostream>


DifficultySelectionDialog::DifficultySelectionDialog(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);

    connect(ui.schema_8_8, &QPushButton::clicked, this, &DifficultySelectionDialog::onStandardGameSelected);
    connect(ui.schema_16_16, &QPushButton::clicked, this, &DifficultySelectionDialog::onMediumGameSelected);
    connect(ui.schema_30_16, &QPushButton::clicked, this, &DifficultySelectionDialog::onHardGameSelected);
    connect(ui.schema_free, &QPushButton::clicked, this, &DifficultySelectionDialog::onCustomizationSelected);

    // Corrigez la connexion pour le bouton Exit
    connect(ui.exitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
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
    std::cout << "MIAOU MIAOU" << std::endl;

    emit customizationRequested();
    //accept(); // Ferme la boîte de dialogue
}
