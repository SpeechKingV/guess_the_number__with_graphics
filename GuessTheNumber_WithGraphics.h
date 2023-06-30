#ifndef GUESSTHENUMBER_WITHGRAPHICS_H
#define GUESSTHENUMBER_WITHGRAPHICS_H

#include <QMainWindow>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QShortcut>
#include <QEvent>
#include <QFileInfo>
#include <QTextStream>
#include <QKeyEvent>
#include <QtWidgets>
#include "ui_GuessTheNumber_WithGraphics.h"

namespace Ui {
class GuessTheNumber_WithGraphics;
}

class GuessTheNumber_WithGraphics : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuessTheNumber_WithGraphics(QVector<int> _settings_,QWidget *parent = nullptr);

    int getlvl()
    {
        return lvl;
    }

    int lvl = 1;


private:

    QVector<int> settings[5];

    QTimer *timer = new QTimer(this);

    int scatter = 100;

    int input = 0;

    int number = 0;

    int remaining_moves = 10;

    int moves = 10;

    Ui::GuessTheNumber_WithGraphics *ui;

signals:

    void win();

    void game_over();

private slots:

    void ok_clicked();

    void clue_clicked();

    int help_clicked();

    void gameOver()
    {
        close();
    }

    void timer_()
    {
        timer->stop();
        ui->ok->setEnabled(true);
        ui->clue->setEnabled(true);
        ui->help->setEnabled(true);
        emit win();
    }

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

        QFile file("Save.txt");

        if(file.open(QIODevice::WriteOnly))
        {
            QFileInfo fileinfo (file);
            QTextStream stream(&file);
//            stream << QString::number(nullptr);
            stream << QString::number(lvl);
            file.close();
        }

        setWindowTitle("Guess The Number|LvL " + QString::number(lvl));

        scatter += scatter;

        ui->answer->setText("Guess the next number from 1 to " + QString::number(scatter));
        QFont font_ = ui->answer->font();
        font_.setPointSize(36);
        ui->answer->setFont(font_);
        ui->answer->setStyleSheet("color: rgb(255, 255, 255)");

        number = 1 + rand() % scatter;

    }
};

#endif // GUESSTHENUMBER_WITHGRAPHICS_H
