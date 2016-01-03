#include "stream.h"
#include "ui_stream.h"

GUI::Stream::Stream(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stream)
{
    ui->setupUi(this);
}

GUI::Stream::~Stream()
{
    delete ui;
}
