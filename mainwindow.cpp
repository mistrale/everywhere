#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDesktopWidget w;
    this->setFixedSize(w.width() * 0.8, w.height() * 0.8 - 5);


    _everywhereWidget = new GUI::EverywhereWindow(this);
    _registrationWidget = new GUI::Registration(this);
    _connectionWidget = new GUI::Connection(this);

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
   _connectionWidget->hide();
   _everywhereWidget->show();
}
