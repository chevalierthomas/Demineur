#ifndef DIFFICULTYSELECTIONDIALOG_H
#define DIFFICULTYSELECTIONDIALOG_H

#include <QDialog>
#include "ui_choose_difficulty.h" // Généré depuis choose_difficulty.ui

class DifficultySelectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit DifficultySelectionDialog(QWidget *parent = nullptr);

signals:
    void gameStartRequested(int width, int height, int mines);
    void customizationRequested();

private slots:
    void onStandardGameSelected();
    void onMediumGameSelected();
    void onHardGameSelected();
    void onCustomizationSelected();

private:
    Ui::ChooseDifficultyDialog ui; // Assurez-vous que le nom Ui::Demineur correspond à celui défini dans votre fichier .ui
};

#endif // DIFFICULTYSELECTIONDIALOG_H
