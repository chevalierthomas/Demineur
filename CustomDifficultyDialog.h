#ifndef CUSTOMDIFFICULTYDIALOG_H
#define CUSTOMDIFFICULTYDIALOG_H

#include <QDialog>
#include "ui_free_difficulty.h" // Généré depuis free_difficulty.ui

class CustomDifficultyDialog : public QDialog {
    Q_OBJECT

public:
    explicit CustomDifficultyDialog(QWidget *parent = nullptr);

    // Méthodes pour récupérer les paramètres de jeu personnalisés
    int getWidth() const;
    int getHeight() const;
    int getMines() const;

signals:
    void cancelClicked();

private:
    Ui::CustomDifficultyDialog ui; // Utilisez le bon espace de noms UI généré par votre fichier .ui
};

#endif // CUSTOMDIFFICULTYDIALOG_H
