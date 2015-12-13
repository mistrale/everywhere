#include "everywherewindow.h"
#include "ui_everywherewindow.h"

GUI::EverywhereWindow::EverywhereWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EverywhereWindow)
{
    ui->setupUi(this);
    _background = new QMovie("C:/Users/Aude/Documents/QT Project/Everywhere/images/sound.gif");
    ui->background->setMovie(_background);
    _background->start();
}

GUI::EverywhereWindow::~EverywhereWindow()
{
    delete ui;
}
