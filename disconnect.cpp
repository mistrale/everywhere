#include "disconnect.h"
#include "ui_disconnect.h"

GUI::Disconnect::Disconnect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Disconnect)
{
    ui->setupUi(this);
}

GUI::Disconnect::~Disconnect()
{
    delete ui;
}
