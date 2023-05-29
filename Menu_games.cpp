#include "Menu_games.h"
#include "ui_Menu_games.h"
#include "GuessTheNumber_WithGraphics.h"
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QFileInfo>

MenuGames::MenuGames(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuGames)
{
    ui->setupUi(this);

    connect(ui->SANG,SIGNAL(clicked()),this,SLOT(SANG_clicked()));
}

void MenuGames::SANG_clicked()
{
    QFile file("Save");
    QFileInfo fileinfo (file);
    QTextStream(&file) << "1";
    file.close();

    GuessTheNumber_WithGraphics w;
    w.show();
    w.setWindowTitle("Guess The Number");
    w.setWindowIcon(QIcon(":/icons/icon.png"));
    //return;
}
