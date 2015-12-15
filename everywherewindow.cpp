#include "everywherewindow.h"
#include "ui_everywherewindow.h"

GUI::EverywhereWindow::EverywhereWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EverywhereWindow)
{
    ui->setupUi(this);
}

GUI::EverywhereWindow::~EverywhereWindow()
{
    delete ui;
}

