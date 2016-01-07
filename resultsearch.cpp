#include "resultsearch.h"
#include "ui_resultsearch.h"

GUI::ResultSearch::ResultSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultSearch)
{
    ui->setupUi(this);
}

GUI::ResultSearch::~ResultSearch()
{
    delete ui;
}
