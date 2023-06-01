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
    explicit GuessTheNumber_WithGraphics(QWidget *parent = nullptr);

//    void set()
//    {
//        remaining_moves = remaining_moves + remaining_moves;
//        ui->moves->setText("remaining moves: " + QString::number(remaining_moves));
//        QFont font = ui->moves->font();
//            font.setPointSize(36);
//            ui->moves->setFont(font);
//        ui->moves->setStyleSheet("color: rgb(255, 255, 255)");

//        scatter += scatter;

//    }

private:

    int scatter = 100;

    int input = 0;

    int number = 0;

    int remaining_moves = 10;

    Ui::GuessTheNumber_WithGraphics *ui;

private slots:

    void ok_clicked();

    void clue_clicked();

    int help_clicked();
};

#endif // GUESSTHENUMBER_WITHGRAPHICS_H
