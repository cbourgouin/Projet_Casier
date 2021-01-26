#include "widget.h"
#include "ui_widget.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase bd;
    bd = QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName("172.18.58.7");
    bd.setDatabaseName("france2018");
    bd.setUserName("snir");
    bd.setPassword("snir");
    if (!bd.open()){
        qDebug()<<"pb acces bd "<< bd.lastError();
    }
    else
    {
        qDebug()<<"acces bd ok";
    }
}

Widget::~Widget()
{
    delete ui;
}

