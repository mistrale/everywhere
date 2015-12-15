#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_everywherewindow.h"

#include <QDesktopWidget>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDesktopWidget w;
    this->setFixedSize(1150, 720);
    _background = new QMovie("C:/Users/Aude/Documents/QT Project/Everywhere/images/sound.gif");
    ui->background->setMovie(_background);
    _background->start();

    QPixmap bkgnd(":/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    _researchWidget = new GUI::Research(this);

    _everywhereWidget = new GUI::EverywhereWindow(this);

    _registrationWidget = new GUI::Registration(this);
    _registrationWidget->move(325, 210);

    _connectionWidget = new GUI::Connection(this);
    _connectionWidget->move(450, 135);

    _everywhereWidget->hide();
    _registrationWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void        MainWindow::showConnection() {
   _registrationWidget->hide();
   _connectionWidget->show();
}

void        MainWindow::showRegistration() {
   _connectionWidget->hide();
   _registrationWidget->show();
}

void        MainWindow::showEverywhere() {
   _background->stop();
   delete _background;
   ui->background->hide();
   _connectionWidget->hide();

   _everywhereWidget->show();
}
