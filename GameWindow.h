#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QSoundEffect>

#include "DifficultySelectionDialog.h"
#include "ScoreManager.h"
#include "ui_game.h" // Assurez-vous que le nom correspond à votre fichier UI généré

class GameWindow : public QDialog {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    explicit GameWindow(DifficultySelectionDialog* difficultyDialog, QWidget *parent = nullptr);
    void setupGame(int width, int height, int mines);

signals:
    void changeDifficultyRequested();

private:
    bool gameFinished = false;
    DifficultySelectionDialog* m_difficultyDialog; // Pointeur vers la fenêtre de sélection de difficulté pour accéder à l'état du son

    Ui::GameWindow ui;

    // Effets sonores utilisés dans le jeu
    QSoundEffect clickSoundEffect;
    QSoundEffect startGameSound;
    QSoundEffect victorySoundEffect;
    QSoundEffect defeatSoundEffect;

    // Grilles pour la logique du jeu
    QVector<QVector<QPushButton*>> buttonGrid;
    QVector<QVector<bool>> mineGrid;
    QVector<QVector<bool>> revealedGrid;
    QVector<QVector<bool>> flagGrid;

    int gameWidth, gameHeight, totalMines;
    const int buttonSize = 40; // Taille standard des boutons dans la grille de jeu

    // Méthodes pour la logique interne du jeu
    void generateMines(int width, int height, int mines);
    void reveal(int x, int y);
    void toggleFlag(int x, int y);
    int countAdjacentMines(int x, int y);
    void checkWinCondition();
    void gameOver(bool win);

    // Slots pour les interactions de l'interface utilisateur
    void changeDifficulty();
    void restartGame();
    void updateFlagCount();

    QTimer *timer; // Timer pour le chronomètre de jeu
    QElapsedTimer startTime;

    void updateTimer(); // Slot pour mettre à jour le chronomètre
    void clearGame(); // Nettoie la grille de jeu pour un nouveau départ ou la fermeture

    bool gameStarted = false; // Suivi de l'état de commencement du jeu
};

#endif // GAMEWINDOW_H
