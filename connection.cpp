#include "connection.h"
#include "ui_connection.h"
#include "requestmanager.h"

#include <QMovie>
#include <QJsonDocument>

#include <iostream>

GUI::Connection::Connection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);

    connect(ui->signinButton, SIGNAL(clicked()), parent, SLOT(showRegistration()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectEverywhere()));


    QObject::connect(_manager.manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    ui->emailEdit->installEventFilter(this);
    ui->passwordEdit->installEventFilter(this);
}

GUI::Connection::~Connection()
{
    delete ui;
}

void            GUI::Connection::connectEverywhere() {
    ui->warningText->setText("");
    _reply = _manager.connectionRequest(ui->emailEdit->text(), ui->passwordEdit->text());
     connect(_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
     _background = new QMovie("C:/Everywhere/images/Ring.gif");
     ui->ring->setMovie(_background);
    _background->start();
}

void            GUI::Connection::replyFinished(QNetworkReply *reply) {
    std::cout << "request ok " << std::endl;
    QByteArray bytes = reply->readAll();
    QJsonDocument doc(QJsonDocument::fromJson(bytes));
    QJsonObject json = doc.object();
    int status = json["status"].toObject().value("code").toInt();

    if (status == 200) {
        ui->warningText->setText("Connection ok!");
        ui->warningText->setStyleSheet("color: green;");
    } else {
        QString message = json["status"].toObject().value("message").toString();
        ui->warningText->setText(message);
        ui->warningText->setStyleSheet("color : red;");
    }
    if (_background != NULL) {
        _background->stop();
        delete _background;
        _background = NULL;
    }
}

void            GUI::Connection::onError(QNetworkReply::NetworkError code) {
    std::cout << "Error on connection request" << std::endl;
    if (_background != NULL) {
        _background->stop();
        delete _background;
        _background = NULL;
    }
}

bool            GUI::Connection::eventFilter(QObject *object, QEvent *event) {
    if(event->type() == QEvent::MouseButtonPress) {
        if (object->objectName() == "emailEdit")
            ui->emailEdit->setText("");
        else if (object->objectName() == "passwordEdit")
            ui->passwordEdit->setText("");
    }
    return false;
}
