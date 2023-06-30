#ifndef SSETTINGS_WINDOW_H
#define SSETTINGS_WINDOW_H

#include <QMainWindow>
#include <QVector>
#include "VolumeOS.h"
#include "ui_Ssettings_window.h"

namespace Ui {
class Ssettings_window;
}

class Ssettings_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ssettings_window(QWidget *parent = nullptr);

    void getSettings(QVector<int> a)
    {
        for (int i = 0;i <=4 ; i++ )
        {
            a.operator[](i) = settings.operator[](i);
        }
    }

private:
    Ui::Ssettings_window *ui;

    QVector<int> settings = {1,1,50,15,15};

private slots:

    void music_checked(bool a)
    {
        if(a)
        {
            settings[0] = 1;

        }
        else
        {
            settings[0] = 0;
        }
    }

    void hints_checked(bool a)
    {
        if(a)
        {
            settings[1] = 1;
        }
        else
        {
            settings[1] = 0;
        }
    }

    void music_volume_changed()
    {
        settings[2] = ui->music_volume->value();
//        VolumeOS VO;
//        VO.VolumeSET(settings[3],true);
    }

    void upper_limit_changed()
    {
        settings[3] = ui->music_volume->value();
    }

    void lower_limit_changet()
    {
        settings[4] = ui->music_volume->value();
    };
};

#endif // SSETTINGS_WINDOW_H
