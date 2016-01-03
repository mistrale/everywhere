#include "download.h"
#include "ui_download.h"

GUI::Download::Download(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Download)
{
    ui->setupUi(this);
}

GUI::Download::~Download()
{
    delete ui;
}
