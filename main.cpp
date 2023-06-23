#include "Menu_games.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

void load_Window(QSplashScreen* psplash)
{

    int i;
    for(i = 0; i < 100; i++)
    {

        QThread::msleep(60);

        psplash->showMessage("Loading : "
                            + QString::number(i)+ "%",
                             Qt::AlignHCenter | Qt::AlignBottom,
                             Qt::white
                             );
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splash(QPixmap(":/loading/loading.jpg"));

    splash.show();

    load_Window(&splash);

    MenuGames mg;
    splash.close();
    mg.show();
    mg.setWindowIcon(QIcon(":/icons/icon.png"));
    mg.setWindowTitle("Guess The Number");

    return a.exec();
}
