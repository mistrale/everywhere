#include "connection.h"
#include "ui_connection.h"
#include "requestmanager.h"

#include <QMovie>

GUI::Connection::Connection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);

    connect(ui->signinButton, SIGNAL(clicked()), parent, SLOT(showRegistration()));
    connect(ui->connectButton, SIGNAL(clicked()), parent, SLOT(showEverywhere()));
}

GUI::Connection::~Connection()
{
    delete ui;
}

void            GUI::Connection::connectEverywhere() {
    Tool::RequestManager  manager;

    QObject::connect(manager.manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    manager.connectionRequest(ui->usernameEdit->text().toStdString(), ui->passwordEdit->text().toStdString());

    _background = new QMovie("C:/Everywhere/images/Ring.gif");
    ui->ring->setMovie(_background);
    _background->start();
}

void            GUI::Connection::replyFinished(QNetworkReply *reply) {

}
