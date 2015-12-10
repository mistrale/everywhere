#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size());
    QPalette palette;
    palette.setColor(menuBar()->backgroundRole(), Qt::white);
    menuBar()->setPalette(palette);
    QObject::connect(&menu, SIGNAL(clicked()), this, SLOT(openMenu()));

    layout = new QGridLayout(&this->widget);
    layout->setGeometry(QRect(100,100,200,200));
    layout->setColumnMinimumWidth(0, 200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <iostream>

void MainWindow::openMenu() {
    static bool isOpen = true;

    if (isOpen) {
        menuList.hide();
        isOpen = false;
        QPropertyAnimation *animation = new QPropertyAnimation(&menuList, "pos");
        animation->setDuration(300);
        animation->setStartValue(menuList.pos());
        animation->setEndValue(QPoint(-200, 41));


        // to slide in call
        animation->start();

    }
    else {
        menuList.show();

        // then a animation:
        QPropertyAnimation *animation = new QPropertyAnimation(&menuList, "pos");
        animation->setDuration(300);
        animation->setStartValue(QPoint(-200, 41));
        animation->setEndValue(menuList.pos());

        // to slide in call
        animation->start();
        isOpen = true;
    }
}
