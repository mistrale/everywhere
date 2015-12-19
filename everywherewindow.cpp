#include "everywherewindow.h"
#include "ui_everywherewindow.h"
#include "ui_news.h"
#include "news.h"

#include <QPropertyAnimation>
#include <QStateMachine>
#include <QSignalTransition>
#include <QTimeLine>

#include <iostream>

GUI::EverywhereWindow::EverywhereWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EverywhereWindow),
    _menuOpen(true)
{
    ui->setupUi(this);
    QObject::connect(ui->menuButton, SIGNAL(clicked()), this, SLOT(manageMenu()));

    createCloseMenu();
    createOpenMenu();

    GUI::News *tata = new GUI::News(this);
    ui->gridLayout->addWidget(tata,2, 0, 1, 2);
    tata->show();
}

GUI::EverywhereWindow::~EverywhereWindow()
{
    delete ui;
}

void            GUI::EverywhereWindow::createQPropertyAnimationButton(const QRect &startGeo,
                                                                      const QRect &endGeo,
                                                                      QPushButton *button,
                                                                      QParallelAnimationGroup *group) {
    QPropertyAnimation *animation = new QPropertyAnimation(button, "geometry");
    animation->setDuration(200);
    animation->setStartValue(startGeo);
    animation->setEndValue(endGeo);
    group->addAnimation(animation);
}

void            GUI::EverywhereWindow::manageMenu() {
    if (_menuOpen) {
        closeMenu();
        _menuOpen = false;
    } else {
        openMenu();
        _menuOpen = true;
    }
}

void            GUI::EverywhereWindow::openMenu() {
    _openLastAnimation->start();
}

void            GUI::EverywhereWindow::closeMenu() {
    _closeAnimations->start();
}

void            GUI::EverywhereWindow::createCloseMenu() {
    _closeAnimations = new QParallelAnimationGroup;
    createQPropertyAnimationButton(QRect(ui->newButton->x(), ui->newButton->y(),
                                         ui->newButton->width(), ui->newButton->height()),
                                   QRect(ui->newButton->x(), ui->newButton->height(),
                                         ui->newButton->width(), 0),ui->newButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->libraryButton->x(), ui->libraryButton->y(),
                                         ui->libraryButton->width(), ui->libraryButton->height()),
                                   QRect(ui->libraryButton->width(), ui->libraryButton->height(),
                                         0, 0),
                                   ui->libraryButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->subscriptionButton->x(), ui->subscriptionButton->y(),
                                         ui->subscriptionButton->width(), ui->subscriptionButton->height()),
                                   QRect(ui->subscriptionButton->y()  - ui->subscriptionButton->width(),
                                         ui->subscriptionButton->height(), 0, 0),
                                   ui->subscriptionButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->streamButton->x(), ui->streamButton->y(),
                                         ui->streamButton->width(), ui->streamButton->height()),
                                   QRect(ui->streamButton->x(), ui->streamButton->y(),
                                         0, ui->streamButton->height()),
                                   ui->streamButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->synchronizationButton->x(), ui->synchronizationButton->y(),
                                         ui->synchronizationButton->width(), ui->synchronizationButton->height()),
                                   QRect(ui->synchronizationButton->width(), ui->synchronizationButton->y(),
                                         0, ui->synchronizationButton->height()),
                                   ui->synchronizationButton,  _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->profilButton->x(), ui->profilButton->y(),
                                         ui->profilButton->width(), ui->profilButton->height()),
                                   QRect(ui->profilButton->width(), ui->profilButton->y(),0, 0),
                                   ui->profilButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->disconnectButton->x(), ui->disconnectButton->y(),
                                         ui->disconnectButton->width(), ui->disconnectButton->height()),
                                   QRect(ui->disconnectButton->x() - ui->disconnectButton->width(),
                                         ui->disconnectButton->y() - ui->disconnectButton->height(), 0, 0),
                                   ui->disconnectButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->downloadButton->x(), ui->downloadButton->y(),
                                         ui->downloadButton->width(), ui->downloadButton->height()),
                                   QRect(ui->downloadButton->x(), ui->downloadButton->y(),
                                         ui->downloadButton->width(), 0),
                                   ui->downloadButton, _closeAnimations);

    _closeLastAnimation = new QPropertyAnimation(ui->shareButton, "geometry");
    _closeLastAnimation->setDuration(200);
    _closeLastAnimation->setStartValue(QRect(ui->shareButton->x(), ui->shareButton->y(),
                                   ui->shareButton->width(), ui->shareButton->height()));
    _closeLastAnimation->setEndValue(QRect(ui->shareButton->width() / 2,
                                           ui->shareButton->height() / 2, 0, 0));
       connect(_closeAnimations, SIGNAL(finished()), _closeLastAnimation, SLOT(start()));
}

void            GUI::EverywhereWindow::createOpenMenu() {
    _openAnimations = new QParallelAnimationGroup;
    createQPropertyAnimationButton(QRect(ui->newButton->x(), ui->newButton->height(),
                                         ui->newButton->width(), 0),
                                   QRect(ui->newButton->x(), ui->newButton->y(),
                                   ui->newButton->width(), ui->newButton->height()),
                                   ui->newButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->libraryButton->width(), ui->libraryButton->height(),
                                         0, 0),
                                   QRect(ui->libraryButton->x(), ui->libraryButton->y(),
                                         ui->libraryButton->width(), ui->libraryButton->height()),
                                   ui->libraryButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->subscriptionButton->x()  - ui->subscriptionButton->width(),
                                         ui->subscriptionButton->height(), 0, 0),
                                   QRect(ui->subscriptionButton->x(), ui->subscriptionButton->y(),
                                         ui->subscriptionButton->width(), ui->subscriptionButton->height()),
                                   ui->subscriptionButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->streamButton->x(), ui->streamButton->y(),
                                         0, ui->streamButton->height()),
                                   QRect(ui->streamButton->x(), ui->streamButton->y(),
                                         ui->streamButton->width(), ui->streamButton->height()),
                                   ui->streamButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->synchronizationButton->width(), ui->synchronizationButton->y(),
                                         0, ui->synchronizationButton->height()),
                                   QRect(ui->synchronizationButton->x(), ui->synchronizationButton->y(),
                                         ui->synchronizationButton->width(), ui->synchronizationButton->height()),
                                   ui->synchronizationButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->profilButton->width(), ui->profilButton->y(),0, 0),
                                   QRect(ui->profilButton->x(), ui->profilButton->y(),
                                         ui->profilButton->width(), ui->profilButton->height()),
                                   ui->profilButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->disconnectButton->x() - ui->disconnectButton->width(),
                                         ui->disconnectButton->y() - ui->disconnectButton->height(), 0, 0),
                                   QRect(ui->disconnectButton->x(), ui->disconnectButton->y(),
                                         ui->disconnectButton->width(), ui->disconnectButton->height()),
                                   ui->disconnectButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->downloadButton->x(), ui->downloadButton->y(),
                                         ui->downloadButton->width(), 0),
                                   QRect(ui->downloadButton->x(), ui->downloadButton->y(),
                                         ui->downloadButton->width(), ui->downloadButton->height()),
                                   ui->downloadButton, _openAnimations);

    _openLastAnimation = new QPropertyAnimation(ui->shareButton, "geometry");
    _openLastAnimation->setDuration(200);
    _openLastAnimation->setEndValue(QRect(ui->shareButton->x(), ui->shareButton->y(),
                                   ui->shareButton->width(), ui->shareButton->height()));
    _openLastAnimation->setStartValue(QRect(ui->shareButton->width() / 2,
                                           ui->shareButton->height() / 2, 0, 0));

    connect(_openLastAnimation, SIGNAL(finished()), _openAnimations, SLOT(start()));
}

