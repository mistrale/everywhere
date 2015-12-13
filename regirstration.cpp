#include "regirstration.h"
#include "ui_regirstration.h"

#include <QMovie>

regirstration::regirstration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regirstration)
{
    ui->setupUi(this);
    QMovie  *movie = new QMovie("C:/Users/Aude/Documents/QT Project/Everywhere/images/sound.gif");
    ui->background->setMovie(movie);
    movie->start();
}

regirstration::~regirstration()
{
    delete ui;
}
