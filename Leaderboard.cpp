#include "Leaderboard.h"
#include "ui_Leaderboard.h"

Leaderboard::Leaderboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Leaderboard)
{
    ui->setupUi(this);

    ui->table->setHorizontalHeaderLabels(QString(" Nickname ; Score").split(";"));

}

