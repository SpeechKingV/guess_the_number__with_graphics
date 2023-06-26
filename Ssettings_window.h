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

    void getSettings(QVector<int>* a)
    {
        a = &settings;
    }

private:
    Ui::Ssettings_window *ui;

    QVector<int> settings = {1,1,50,15,15};

private slots:

    void music_checked(bool a)
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

    void hints_checked(bool a)
    {
        if(a)
        {
            settings[2] = 1;
        }
        else
        {
            settings[2] = 0;
        }
    }

    void music_volume_changed()
    {
        settings[3] = ui->music_volume->value();
        VolumeOS VO;
        VO.VolumeSET(settings[3],true);
    }

    void upper_limit_changed()
    {
        settings[4] = ui->music_volume->value();
    }

    void lower_limit_changet()
    {
        settings[5] = ui->music_volume->value();
    };
};

#endif // SSETTINGS_WINDOW_H
