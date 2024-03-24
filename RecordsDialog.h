#ifndef RECORDSDIALOG_H
#define RECORDSDIALOG_H

#include <QDialog>
#include "ui_records.h" // Assurez-vous que ce nom correspond au nom du fichier header généré pour records.ui

class RecordsDialog : public QDialog {
    Q_OBJECT

public:
    explicit RecordsDialog(QWidget *parent = nullptr);

private slots:
    void onClearButtonClicked();  // Ajoutez cette ligne

private:
    Ui::RecordsDialog ui;
    void loadAndDisplayScores();

protected:
    void showEvent(QShowEvent *event) override;
};



#endif // RECORDSDIALOG_H
