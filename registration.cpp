#include "registration.h"
#include "ui_registration.h"

GUI::Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    _background = new QMovie("C:/Users/Aude/Documents/QT Project/Everywhere/images/sound.gif");
    ui->background->setMovie(_background);
    _background->start();

    connect(ui->backButton, SIGNAL(clicked()), parent, SLOT(showConnection()));
}

GUI::Registration::~Registration()
{
    delete ui;
}
