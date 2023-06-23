#include "GuessTheNumber_WithGraphics.h"
#include "ui_GuessTheNumber_WithGraphics.h"

GuessTheNumber_WithGraphics::GuessTheNumber_WithGraphics(QVector<int> settings,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuessTheNumber_WithGraphics)
{
    srand(time(NULL));

    //clue
    if(!settings[2])
    {
        ui->clue->setEnabled(true);
    }

    ui->setupUi(this);

    QValidator *validator = new QIntValidator(1,100,this);
    ui->lineEdit->setValidator(validator);

    connect(ui->ok,SIGNAL(clicked()),this,SLOT(ok_clicked()));
    connect(ui->clue,SIGNAL(clicked()),this,SLOT(clue_clicked()));
    connect(ui->help,SIGNAL(clicked()),this,SLOT(help_clicked()));
    connect(this,SIGNAL(win()),this,SLOT(set()));

    number = 1 + rand() % scatter;
}

void GuessTheNumber_WithGraphics::ok_clicked()
{

    if(remaining_moves < 0)
    {
        ui->answer->setText("You lose! \n you've run out of moves");
        QFont font = ui->answer->font();
        font.setPointSize(36);
        ui->answer->setFont(font);
        ui->answer->setStyleSheet("color: rgb(255, 0, 0)");
    }

    input = ui->lineEdit->text().toInt();

    remaining_moves = remaining_moves -1;

    ui->moves->setText("remaining moves: " + QString::number(remaining_moves));
    QFont font = ui->moves->font();
    font.setPointSize(36);
    ui->moves->setFont(font);
    ui->moves->setStyleSheet("color: rgb(255, 255, 255)");

    if(number == input)
    {
        ui->answer->setText("You win!");
        font = ui->answer->font();
        font.setPointSize(36);
        ui->answer->setFont(font);
        ui->answer->setStyleSheet("color: rgb(0, 255, 0)");

        emit win();
    }
    else if(number > input)
    {
        ui->answer->setText("My number is higher!");
        font = ui->answer->font();
        font.setPointSize(36);
        ui->answer->setFont(font);
        ui->answer->setStyleSheet("color: rgb(255, 255, 255)");
    }
    else if(number < input)
    {
        ui->answer->setText("My number is less!");
        font = ui->answer->font();
        font.setPointSize(36);
        ui->answer->setFont(font);
        ui->answer->setStyleSheet("color: rgb(255, 255, 255)");
    }

    if(remaining_moves < 0)
    {
        ui->answer->setText("You lose! \n you've run out of moves");
        font = ui->answer->font();
        font.setPointSize(36);
        ui->answer->setFont(font);
        ui->answer->setStyleSheet("color: rgb(255, 0, 0)");
        emit game_over();
    }
}

void GuessTheNumber_WithGraphics::clue_clicked()
{
    if(remaining_moves < 0)
    {
        ui->answer->setText("You lose! \n you've run out of moves");
        QFont font = ui->answer->font();
        font.setPointSize(36);
        ui->answer->setFont(font);
        ui->answer->setStyleSheet("color: rgb(255, 0, 0)");
        close();
    }

    remaining_moves = remaining_moves -1;

    ui->moves->setText("remaining moves: " + QString::number(remaining_moves));
    QFont font = ui->moves->font();
    font.setPointSize(36);
    ui->moves->setFont(font);
    ui->moves->setStyleSheet("color: rgb(255, 255, 255)");

    srand(time(NULL));

    int temp = -10 + rand() % 13;
    int clue = number + temp;

    ui->answer->setText("Clue: around " + QString::number(clue));
    font = ui->answer->font();
    font.setPointSize(36);
    ui->answer->setFont(font);
    ui->answer->setStyleSheet("color: rgb(255, 255, 255)");


    if(remaining_moves < 0)
    {
        ui->answer->setText("You lose! \n you've run out of moves");
        QFont font = ui->answer->font();
        font.setPointSize(36);
        ui->answer->setFont(font);
        ui->answer->setStyleSheet("color: rgb(255, 0, 0)");
    }

    return;
}
int GuessTheNumber_WithGraphics::help_clicked()
{
    QMessageBox help_message;
    help_message.setInformativeText("this is a small \"guess the number\" game. In it, you have to guess a random number. \ncontrol:\nOK - send answer\nclue - gives a hint\nhelp - opens a help window\nif you can't guess the number, use the hint.\nIf you still can’t guess, then try to enter 50 first, then 25 or 75, and so on.");
    help_message.show();
    help_message.setIconPixmap(QPixmap(":/icons/information.png"));
    return help_message.exec();
}
