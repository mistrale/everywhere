#include "everywherewindow.h"
#include "ui_everywherewindow.h"

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

    //
    // ANIMATION CLOSE MENU
    //
    _closeAnimations = new QParallelAnimationGroup;
    createQPropertyAnimationButton(QRect(ui->newButton->x(), ui->newButton->y(),
                                         ui->newButton->width(), ui->newButton->height()),
                                   QRect(ui->newButton->width(), ui->newButton->height(),
                                         0, 0),ui->newButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->libraryButton->x(), ui->libraryButton->y(),
                                         ui->libraryButton->width(), ui->libraryButton->height()),
                                   QRect(ui->libraryButton->x(), ui->libraryButton->height(),
                                         ui->libraryButton->width(), 0),
                                   ui->libraryButton, _closeAnimations);
    createQPropertyAnimationButton(QRect(ui->shareButton->x(), ui->shareButton->y(),
                                         ui->shareButton->width(), ui->shareButton->height()),
                                   QRect(ui->shareButton->x()  - ui->shareButton->width(),
                                         ui->shareButton->height(), 0, 0),
                                   ui->shareButton, _closeAnimations);
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

    //
    // ANIMATION OPEN MENU
    //
    _openAnimations = new QParallelAnimationGroup;
    createQPropertyAnimationButton(QRect(ui->newButton->width(), ui->newButton->height(), 0, 0),
                                   QRect(ui->newButton->x(), ui->newButton->y(),
                                   ui->newButton->width(), ui->newButton->height()),
                                   ui->newButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->libraryButton->x(), ui->libraryButton->height(),
                                         ui->libraryButton->width(), 0),
                                   QRect(ui->libraryButton->x(), ui->libraryButton->y(),
                                         ui->libraryButton->width(), ui->libraryButton->height()),
                                   ui->libraryButton, _openAnimations);
    createQPropertyAnimationButton(QRect(ui->shareButton->x()  - ui->shareButton->width(),
                                         ui->shareButton->height(), 0, 0),
                                   QRect(ui->shareButton->x(), ui->shareButton->y(),
                                         ui->shareButton->width(), ui->shareButton->height()),
                                   ui->shareButton, _openAnimations);
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

    _test = new QPropertyAnimation(ui->subscriptionButton, "geometry");
    _test->setDuration(500);
    _test->setStartValue(QRect(ui->subscriptionButton->x(), ui->subscriptionButton->y(),
                                   ui->subscriptionButton->width(), ui->subscriptionButton->height()));
    _test->setEndValue(QRect(ui->subscriptionButton->width() / 2, ui->subscriptionButton->height() / 2, 0, 0));



    _test2 = new QGraphicsItemAnimation(ui->subscriptionButton);
    _test2->setTimeLine(new QTimeLine);
    _test2->setTranslationAt(0.5, ui->subscriptionButton->x() + ui->subscriptionButton->width() / 2,
                             ui->subscriptionButton->y() + ui->subscriptionButton->height() / 2);


    connect(_closeAnimations, SIGNAL(finished()), _test, SLOT(start()));
    connect(_closeAnimations, SIGNAL(finished()), _test2, SLOT(start()));
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
    animation->setDuration(500);
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
    _openAnimations->start();
}

void            GUI::EverywhereWindow::closeMenu() {
    _closeAnimations->start();
}

