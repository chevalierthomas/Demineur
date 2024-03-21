#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer> // Ajoutez cette ligne ici

#include "ui_game.h" // Assurez-vous que le nom correspond à votre fichier UI généré

class GameWindow : public QDialog {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    void setupGame(int width, int height, int mines);


signals:
    void changeDifficultyRequested();

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

    void changeDifficulty(); // Slot pour gérer le changement de difficulté
    void restartGame(); // Slot pour redémarrer le jeu

    void updateFlagCount(); // Méthode pour mettre à jour le compteur de drapeaux

    QTimer *timer;  // Pour l'actualisation du temps
    QElapsedTimer startTime;

    void updateTimer(); // Slot pour mettre à jour le chronomètre chaque seconde
    void clearGame();

    bool gameStarted = false; // Ajoutez cette ligne pour suivre si le jeu a commencé


    // Ajoutez d'autres méthodes nécessaires ici
};

#endif // GAMEWINDOW_H

