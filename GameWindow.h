#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "ui_game.h" // Généré depuis game.ui

class GameWindow : public QDialog {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    void setupGame(int width, int height, int mines);

private:
    Ui::GameWindow ui;
    void generateGameBoard(int width, int height, int mines);
};

#endif // GAMEWINDOW_H
