#include "Menu_games.h"
#include "ui_Menu_games.h"
#include "Ssettings_window.h"
#include "GuessTheNumber_WithGraphics.h"
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QThread>

#include <windows.h>
#include <conio.h>
#include <mmsystem.h>//sndPlaySound
#include <stdio.h>
#include <tchar.h>
//#pragma comment(lib, "winmm.lib")

MenuGames::MenuGames(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuGames)
{
    ui->setupUi(this);

    //music
//    if(!settings[1])
//    {
//        wchar_t path[]=L"1.wav";// TAM, rDE "*.exe"
//            PlaySound(path, NULL, SND_FILENAME);
//    }


    connect(ui->SANG,SIGNAL(clicked()),this,SLOT(SANG_clicked()));
    connect(ui->continue_2,SIGNAL(clicked()),this,SLOT(continue_clicked()));
    connect(ui->settings,SIGNAL(clicked()),this,SLOT(settings_cliked()));



    QFile file("Save.txt");
    if(file.open(QIODevice::WriteOnly))
    {
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
}

void MenuGames::SANG_clicked()
{
    QFile file("Save.txt");

    if(file.open(QIODevice::WriteOnly))
    {
        QFileInfo fileinfo (file);
        QTextStream(&file) << "1";
        file.close();
    }

    GuessTheNumber_WithGraphics* w = new GuessTheNumber_WithGraphics(settings);
    w->show();
    w->setWindowTitle("Guess The Number|LeveL 1");
    w->setWindowIcon(QIcon(":/icons/icon.png"));

}

void MenuGames::continue_clicked()
{
    QFile file("Save.txt");
    QString str;
    if(file.open(QIODevice::WriteOnly))
    {
        QFileInfo fileinfo (file);
        QTextStream stream(&file);
        str = stream.readAll();
    }

    if(str == nullptr)
    {
        qDebug() << "Save Null";
        SANG_clicked();
        return;
    }

    int i = str.toInt()-1;

    GuessTheNumber_WithGraphics* w = new GuessTheNumber_WithGraphics(settings);
    w->show();
    w->setWindowTitle("Guess The Number|LeveL 1");
    w->setWindowIcon(QIcon(":/icons/icon.png"));

    file.close();

}

void MenuGames::settings_cliked()
{
    Ssettings_window* w = new Ssettings_window;
    w->show();
    w->setWindowIcon(QIcon(":/icons/settings.png"));
    w->setWindowTitle("Guess The Number|Settings");
    if(w->isHidden())
    {
        w->getSettings(&settings);
    }
}
