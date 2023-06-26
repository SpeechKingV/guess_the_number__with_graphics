#ifndef MENU_GAMES_H
#define MENU_GAMES_H

#include <QMainWindow>
#include <QString>
#include "Leaderboard.h"

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

    QVector<int> settings = {1,1,50,15,15};

private slots:

    void SANG_clicked();
    void settings_cliked();
    void continue_clicked();
    void leaderboard_clicked();

};

#endif // MENU_GAMES_H
