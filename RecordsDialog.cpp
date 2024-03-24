#include "RecordsDialog.h"
#include "ScoreManager.h" // Assurez-vous d'inclure ScoreManager
#include <QMessageBox>

RecordsDialog::RecordsDialog(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);

    connect(ui.returnButton, &QPushButton::clicked, this, &RecordsDialog::close);
    connect(ui.clearButton, &QPushButton::clicked, this, &RecordsDialog::onClearButtonClicked);  // Connectez le signal clicked du bouton clear à votre nouveau slot

    // Charger les scores et les afficher
    loadAndDisplayScores();
}

void RecordsDialog::loadAndDisplayScores() {
    auto scores = ScoreManager::instance().loadScores(); // Utilisez votre méthode de chargement de scores
    ui.scoresTable->setRowCount(scores.size());
    ui.scoresTable->setColumnCount(4); // Assurez-vous que cela correspond au nombre de colonnes de votre tableau

    QStringList headers = {"Name", "Time", "Height", "Width"};
    ui.scoresTable->setHorizontalHeaderLabels(headers);

    int row = 0;
    for (const auto& score : scores) {
        ui.scoresTable->setItem(row, 0, new QTableWidgetItem(score.playerName));
        ui.scoresTable->setItem(row, 1, new QTableWidgetItem(score.time.toString("mm:ss")));
        ui.scoresTable->setItem(row, 2, new QTableWidgetItem(QString::number(score.height)));
        ui.scoresTable->setItem(row, 3, new QTableWidgetItem(QString::number(score.width)));
        ++row;
    }

    ui.scoresTable->resizeColumnsToContents(); // Optionnel, pour un meilleur affichage
}

void RecordsDialog::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);
    loadAndDisplayScores(); // Rafraîchir les scores à chaque affichage
}

void RecordsDialog::onClearButtonClicked() {
    // Demander confirmation avant de supprimer les scores
    auto reply = QMessageBox::question(this, tr("Confirmer la suppression"), tr("Êtes-vous sûr de vouloir supprimer tous les scores ?"), QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ScoreManager::instance().clearScores(); // Appelez une méthode de ScoreManager pour effacer les scores
        loadAndDisplayScores(); // Rechargez et affichez à nouveau les scores (qui devraient maintenant être vides)
    }
}
