#include "library.h"
#include "ui_library.h"

GUI::Library::Library(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Library)
{
    ui->setupUi(this);
}

GUI::Library::~Library()
{
    delete ui;
}
