#ifndef DIFFICULTYSELECTIONDIALOG_H
#define DIFFICULTYSELECTIONDIALOG_H

#include <QDialog>
#include <QSoundEffect> // Assurez-vous d'inclure QSoundEffect ici

#include "ui_choose_difficulty.h" // Généré depuis choose_difficulty.ui
#include "RecordsDialog.h"


class DifficultySelectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit DifficultySelectionDialog(QWidget *parent = nullptr);
    bool isSoundEnabled() const { return soundEnabled; }

signals:
    void gameStartRequested(int width, int height, int mines);
    void customizationRequested();

private slots:
    void onStandardGameSelected();
    void onMediumGameSelected();
    void onHardGameSelected();
    void onCustomizationSelected();
    void onExitRequested();
    void onToggleSound();
    void onShowScores();

private:
    Ui::ChooseDifficultyDialog ui;
    QSoundEffect exitGameSoundEffect;
    bool soundEnabled = true;
    RecordsDialog* recordsDialog;

    void updateSoundButtonIcon(); // Méthode pour mettre à jour l'icône du bouton son
};

#endif // DIFFICULTYSELECTIONDIALOG_H
