#include "Menu_games.h"
#include "ui_Menu_games.h"
#include "GuessTheNumber_WithGraphics.h"
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QThread>


MenuGames::MenuGames(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuGames)
{
    ui->setupUi(this);

    connect(ui->SANG,SIGNAL(clicked()),this,SLOT(SANG_clicked()));
    connect(ui->continue_2,SIGNAL(clicked()),this,SLOT(continue_clicked()));


    QFile file("Save.txt");
    file.open(QIODevice::WriteOnly);
    QFileInfo fileinfo (file);
    QTextStream stream(&file);
    QString str = stream.readAll();

    if(str == nullptr)
    {
        ui->continue_2->setEnabled(false);
    }
    else
    {
        ui->continue_2->setEnabled(true);
    }
    file.close();
}

void MenuGames::SANG_clicked()
{
    QFile file("Save.txt");
    file.open(QIODevice::WriteOnly);
    QFileInfo fileinfo (file);
    QTextStream(&file) << "1";
    file.close();

    QThread* thread = new QThread();

    GuessTheNumber_WithGraphics* w = new GuessTheNumber_WithGraphics;
    w->moveToThread(thread);
    w->show();
    w->setWindowTitle("Guess The Number|LeveL 1");
    w->setWindowIcon(QIcon(":/icons/icon.png"));

//    for (int i = 1; i <= 100;i++ )
//    {
//        thread->wait();
//        w->set();
//        w->show();
//    }
}

void MenuGames::continue_clicked()
{
    QFile file("Save.txt");
    file.open(QIODevice::WriteOnly);
    QFileInfo fileinfo (file);
    QTextStream stream(&file);
    QString str = stream.readAll();

    if(str == nullptr)
    {
        qDebug() << "Save Null";
        SANG_clicked();
        return;
    }

    int i = str.toInt()-1;

    for(;i<101;i++)
    {


    }
    file.close();

}
