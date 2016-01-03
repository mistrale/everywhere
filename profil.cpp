#include "profil.h"
#include "ui_profil.h"

GUI::Profil::Profil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Profil)
{
    ui->setupUi(this);
}

GUI::Profil::~Profil()
{
    delete ui;
}
