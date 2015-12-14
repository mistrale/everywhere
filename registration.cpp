#include "registration.h"
#include "ui_registration.h"

GUI::Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    connect(ui->backButton, SIGNAL(clicked()), parent, SLOT(showConnection()));
}

GUI::Registration::~Registration()
{
    delete ui;
}
