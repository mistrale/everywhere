#include "registration.h"
#include "ui_registration.h"

GUI::Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    connect(ui->backButton, SIGNAL(clicked()), parent, SLOT(showConnection()));
    connect(ui->signinButton, SIGNAL(clicked()), this, SLOT(registerEverywhere()));
}

GUI::Registration::~Registration()
{
    delete ui;
}

void            GUI::Registration::registerEverywhere() {
    _background = new QMovie("C:/Everywhere/images/Ring.gif");
    ui->ring->setMovie(_background);
    _background->start();
}
