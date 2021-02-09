#include "interfacedescasiers.h"
#include "ui_interfacedescasiers.h"

InterfaceDesCasiers::InterfaceDesCasiers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InterfaceDesCasiers)
{
    ui->setupUi(this);
}

InterfaceDesCasiers::~InterfaceDesCasiers()
{
    delete ui;
}

