#include "GuessTheNumber_WithGraphics.h"
#include "ui_GuessTheNumber_WithGraphics.h"

GuessTheNumber_WithGraphics::GuessTheNumber_WithGraphics(QVector<int> _settings_,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuessTheNumber_WithGraphics)
{
    srand(time(NULL));
    for (int i = 0;i < 4 ; i++ )
    {
        settings->operator[](i) = _settings_.operator[](i);
    }
    //clue
    if(!settings->operator[](1))
    {
        ui->clue->setEnabled(true);
    }

    ui->setupUi(this);

    ui->ok->setShortcut(Qt::Key_Enter);
    ui->ok->setDefault(true);
    ui->ok->setAutoDefault(true);
    ui->lineEdit->setPlaceholderText(QString::fromLocal8Bit("input number"));


    QValidator *validator = new QIntValidator(1,10000000,this);
    ui->lineEdit->setValidator(validator);

    connect(ui->ok,SIGNAL(clicked()),this,SLOT(ok_clicked()));
    connect(ui->clue,SIGNAL(clicked()),this,SLOT(clue_clicked()));
    connect(ui->help,SIGNAL(clicked()),this,SLOT(help_clicked()));
    connect(this,SIGNAL(win()),this,SLOT(set()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_()));
    connect(ui->lineEdit,SIGNAL(returnPressed),this,SLOT(ok_clicked()));

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
        ui->ok->setEnabled(false);
        ui->clue->setEnabled(false);
        ui->help->setEnabled(false);
        timer->start(5000);
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

    int temp = -settings->operator[](4)+ rand() % settings->operator[](3);
    qDebug() << "-" << settings->operator[](4) << "+" << settings->operator[](3);
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
