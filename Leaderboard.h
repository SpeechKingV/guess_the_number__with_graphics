#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QMainWindow>

namespace Ui {
class Leaderboard;
}

class Leaderboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Leaderboard(QWidget *parent = nullptr);

private:
    Ui::Leaderboard *ui;
};

#endif // LEADERBOARD_H
