#include "interfacedescasiers.h"
#include "ui_interfacedescasiers.h"


InterfaceDesCasiers::InterfaceDesCasiers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InterfaceDesCasiers)
{
    ui->setupUi(this);
    for(int i=0; i<NBDECASIERS; i++){
        lesBoutons[i] = new QPushButton();
        connect(lesBoutons[i], &QPushButton::clicked, this, &InterfaceDesCasiers::onpushButtonMaterielsclicked);
        lesBoutons[i]->setFixedSize(100, 100);
    }
    int compteur = 0;
    for(int etage=0; etage<4; etage++){
        for(int colonne=0; colonne<3; colonne++){
            if(etage != 1 || colonne != 1){
                ui->gridLayout->addWidget(lesBoutons[compteur], etage, colonne);
                compteur++;
            }
        }
    }
    //gridLayoutWidget->setParent(this);
    gridLayoutWidget->setGeometry(QRect(200, 60, 160, 80));

}

InterfaceDesCasiers::~InterfaceDesCasiers()
{
    delete ui;
}

void InterfaceDesCasiers::onpushButtonMaterielsclicked()
{

}

int InterfaceDesCasiers::getValue() const
{
    return value;
}

void InterfaceDesCasiers::setValue(int value)
{
    value = value;
}
