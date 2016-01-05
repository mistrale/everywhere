#include "registration.h"
#include "ui_registration.h"
#include "requestmanager.h"

#include <QNetworkReply>
#include <QJsonDocument>

#include <iostream>

GUI::Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    connect(ui->backButton, SIGNAL(clicked()), parent, SLOT(showConnection()));
    connect(ui->signinButton, SIGNAL(clicked()), this, SLOT(registerEverywhere()));

    QObject::connect(_manager.manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    ui->emailEdit->installEventFilter(this);
    ui->usernameEdit->installEventFilter(this);
    ui->passwordEdit->installEventFilter(this);
    ui->passwordConfirmationEdit->installEventFilter(this);
}

GUI::Registration::~Registration()
{
    delete ui;
}

void            GUI::Registration::registerEverywhere() {
    ui->warningText->setText("");
    std::cout << "On rentre la" << std::endl;


    _reply = _manager.registrationRequest(ui->usernameEdit->text(), ui->passwordEdit->text(), ui->emailEdit->text());

     connect(_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));

     _background = new QMovie("C:/Everywhere/images/Ring.gif");
     ui->ring->setMovie(_background);
    _background->start();
}

void            GUI::Registration::replyFinished(QNetworkReply *reply) {
    QByteArray bytes = reply->readAll();
    QJsonDocument doc(QJsonDocument::fromJson(bytes));
    QJsonObject json = doc.object();
    int status = json["status"].toObject().value("code").toInt();

    if (status == 200) {
        ui->warningText->setText("Account created !");
        ui->warningText->setStyleSheet("color: green; 	font: 12pt \"MS Shell Dlg 2\";font-weight: bold;");
    } else {
        QString message = json["status"].toObject().value("message").toString();
        ui->warningText->setText(message);
        ui->warningText->setStyleSheet("color : red;");
    }
    _background->stop();
    delete _background;
}

void            GUI::Registration::onError(QNetworkReply::NetworkError code) {
    std::cout << "Error on registration request" << std::endl;
    _background->stop();
    delete _background;
}

bool            GUI::Registration::eventFilter(QObject *object, QEvent *event) {
    if(event->type() == QEvent::MouseButtonPress) {
        if (object->objectName() == "emailEdit")
            ui->emailEdit->setText("");
        else if (object->objectName() == "usernameEdit")
            ui->usernameEdit->setText("");
        else if (object->objectName() == "passwordEdit")
            ui->passwordEdit->setText("");
        else if (object->objectName() == "passwordConfirmationEdit")
            ui->passwordConfirmationEdit->setText("");
    }
    return false;
}
