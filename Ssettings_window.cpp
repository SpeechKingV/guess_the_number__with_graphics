#include "Ssettings_window.h"
#include "ui_Ssettings_window.h"

Ssettings_window::Ssettings_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ssettings_window)
{
    ui->setupUi(this);

    connect(ui->hints,SIGNAL(pressed(bool)),this,SLOT(hints_checked(bool)));
    connect(ui->music,SIGNAL(pressed(bool)),this,SLOT(music_checked(bool)));

}
