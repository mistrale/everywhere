#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_everywherewindow.h"

#include <QDir>
#include <QDesktopWidget>

#include <iostream>

#define WIN_WIDTH 1000
#define WIN_HEIGHT 800

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDesktopWidget w;
    this->setFixedSize(WIN_WIDTH, WIN_HEIGHT);

    std::string pathcurrent = QDir::currentPath().toStdString().substr(0, pathcurrent.find_last_of("/"));
    pathcurrent = pathcurrent.substr(0, pathcurrent.find_last_of("/"));
    _background = new QMovie(std::string(pathcurrent + "/everywhere/images/sound.gif").c_str());
    ui->background->setMovie(_background);
    _background->start();



    _everywhereWidget = new GUI::EverywhereWindow(this);

    _registrationWidget = new GUI::Registration(this);
    _registrationWidget->move((WIN_WIDTH - 498) / 2, (WIN_HEIGHT - 299) / 2);

    _connectionWidget = new GUI::Connection(this);
    _connectionWidget->move((WIN_WIDTH - 250)/ 2, (WIN_HEIGHT - 450) / 2);

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
