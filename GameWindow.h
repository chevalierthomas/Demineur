#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include "ui_game.h" // Assurez-vous que le nom correspond à votre fichier UI généré

class GameWindow : public QDialog {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    void setupGame(int width, int height, int mines);

private:
    Ui::GameWindow ui;
    QVector<QVector<QPushButton*>> buttonGrid;
    QVector<QVector<bool>> mineGrid;
    QVector<QVector<bool>> revealedGrid;
    QVector<QVector<bool>> flagGrid;
    int gameWidth, gameHeight, totalMines;
    const int buttonSize = 40; // Définissez ici la taille de vos boutons


    void generateMines(int width, int height, int mines);
    void reveal(int x, int y);
    void toggleFlag(int x, int y);
    int countAdjacentMines(int x, int y);
    void checkWinCondition();
    void gameOver(bool win);

    // Ajoutez d'autres méthodes nécessaires ici
};

#endif // GAMEWINDOW_H

