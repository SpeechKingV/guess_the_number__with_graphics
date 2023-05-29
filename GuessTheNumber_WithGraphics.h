#ifndef GUESSTHENUMBER_WITHGRAPHICS_H
#define GUESSTHENUMBER_WITHGRAPHICS_H

#include <QMainWindow>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include <QMutex>

namespace Ui {
class GuessTheNumber_WithGraphics;
}

class GuessTheNumber_WithGraphics : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuessTheNumber_WithGraphics(QWidget *parent = nullptr);

private:

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
