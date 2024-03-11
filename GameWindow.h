#include <QDialog>
#include <QPushButton>
#include <QVector>
#include <QGridLayout>
#include "ui_game.h" // Assurez-vous que le nom correspond à votre fichier UI généré

class GameWindow : public QDialog {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    void setupGame(int width, int height, int mines);

private:
    Ui::GameWindow ui;
    QVector<QVector<QPushButton*>> buttonGrid; // Grille de boutons
    void generateMines(int width, int height, int mines);
    void reveal(int x, int y); // Révèle la case et gère la logique de jeu
};

