#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , bus1(0x20)
    , bus2(0x21)
{
    ui->setupUi(this);

    bus1.set_bus_direction(0x00);
    bus2.set_bus_direction(0x01);// set the direction for bank 1 to be outputs
    bus1.write_bus(0xFF);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "Eteindre"){
        bus1.write_pin(1, 1); // turn pin 1 off
        bus1.write_pin(2, 0);
        ui->pushButton->setText("Allumer");
    }
    else{
        bus1.write_pin(1, 0); // turn pin 1 on
        bus1.write_pin(2, 1);
        ui->pushButton->setText("Eteindre");
    }

}

void Widget::on_pushButton_2_clicked()
{
    uint8_t val1 = bus2.read_pin(1);
    uint8_t val2 = bus2.read_pin(2);
    if(val1 == 1){
        ui->checkBox->setChecked(true);
    }else{
        ui->checkBox->setChecked(false);
    }
    if(val2 == 1){
        ui->checkBox_2->setChecked(true);
    }else{
        ui->checkBox_2->setChecked(false);
    }
}
