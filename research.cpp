#include "research.h"
#include "ui_research.h"

GUI::Research::Research(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Research)
{
    ui->setupUi(this);
}

GUI::Research::~Research()
{
    delete ui;
}
