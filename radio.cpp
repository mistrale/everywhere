#include "radio.h"
#include "ui_radio.h"

GUI::Radio::Radio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Radio)
{
    ui->setupUi(this);
}

GUI::Radio::~Radio()
{
    delete ui;
}
