#include "news.h"
#include "ui_news.h"

GUI::News::News(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::News)
{
    ui->setupUi(this);
}

GUI::News::~News()
{
    delete ui;
}
