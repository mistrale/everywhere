#include "connection.h"
#include "ui_connection.h"

#include <QMovie>

GUI::Connection::Connection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
    _background = new QMovie("C:/Users/Aude/Documents/QT Project/Everywhere/images/sound.gif");
    ui->background->setMovie(_background);
    _background->start();

    connect(ui->signinButton, SIGNAL(clicked()), parent, SLOT(showRegistration()));
    connect(ui->connectButton, SIGNAL(clicked()), parent, SLOT(showEverywhere()));
}

GUI::Connection::~Connection()
{
    delete ui;
}
