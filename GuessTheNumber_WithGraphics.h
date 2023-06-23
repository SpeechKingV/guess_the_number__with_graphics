#ifndef GUESSTHENUMBER_WITHGRAPHICS_H
#define GUESSTHENUMBER_WITHGRAPHICS_H

#include <QMainWindow>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include <QThread>
#include "ui_GuessTheNumber_WithGraphics.h"

namespace Ui {
class GuessTheNumber_WithGraphics;
}

class GuessTheNumber_WithGraphics : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuessTheNumber_WithGraphics(QVector<int> settings,QWidget *parent = nullptr);

private:

    int scatter = 100;

    int input = 0;

    int number = 0;

    int remaining_moves = 10;

    int moves = 10;

    int lvl = 1;

    Ui::GuessTheNumber_WithGraphics *ui;

signals:

    void win();

    void game_over();

private slots:

    void ok_clicked();

    void clue_clicked();

    int help_clicked();

    void set()
    {
        srand(time(NULL));
        moves = moves + moves;
        remaining_moves += moves;
        ui->moves->setText("remaining moves: " + QString::number(remaining_moves));
        QFont font = ui->moves->font();
            font.setPointSize(36);
            ui->moves->setFont(font);
        ui->moves->setStyleSheet("color: rgb(255, 255, 255)");

        lvl++;

        setWindowTitle("Guess The Number|LvL " + QString(lvl));


        scatter += scatter;
        number = 1 + rand() % scatter;

    }
};

#endif // GUESSTHENUMBER_WITHGRAPHICS_H
