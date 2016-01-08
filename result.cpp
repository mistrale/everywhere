#include "result.h"
#include "ui_result.h"

#include <iostream>

GUI::Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);

    _player = new QMediaPlayer(this);
    _video = new QVideoWidget(this);
    _playlist = new QMediaPlaylist(this);

    QUrl    url = QUrl::fromLocalFile("C:/Users/audes_000/Downloads/test/test.mp4");
    _playlist->addMedia(url);
    std::cout << "C'est valide " << url.isValid() << std::endl;
    _playlist->setCurrentIndex(1);
    _player->setPlaylist(_playlist);
    _player->setVideoOutput(_video);
    _video->setGeometry(0, 0, 1000, 750);
    _video->show();
    //_player->play();

    test = new QPushButton(this);
    test->setText("PWET");
    test->setGeometry(0 , 0, 200, 200);
    test->show();
}

GUI::Result::~Result()
{
    delete ui;
}
