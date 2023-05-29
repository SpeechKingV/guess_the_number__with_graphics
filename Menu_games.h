#ifndef MENU_GAMES_H
#define MENU_GAMES_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MenuGames;
}

class MenuGames : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuGames(QWidget *parent = nullptr);


private:
    Ui::MenuGames *ui;


private slots:

    void SANG_clicked();
    //void settings_cliked();

};

#endif // MENU_GAMES_H
