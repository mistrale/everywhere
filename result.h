#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

#include <QPushButton>

namespace Ui {
class Result;
}

namespace GUI {
    class Result : public QWidget
    {
        Q_OBJECT

    public:
        explicit Result(QWidget *parent = 0);
        ~Result();

    private:
        Ui::Result *ui;

        QVideoWidget    *_video;
        QMediaPlayer    *_player;
        QMediaPlaylist  *_playlist;

        QPushButton     *test;
    };
}

#endif // RESULT_H
