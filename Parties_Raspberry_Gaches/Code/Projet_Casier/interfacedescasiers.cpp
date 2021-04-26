#include "interfacedescasiers.h"
#include "ui_interfacedescasiers.h"


InterfaceDesCasiers::InterfaceDesCasiers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InterfaceDesCasiers)
{
    ui->setupUi(this);
    grille = new QGridLayout();
    gridLayoutWidget = new QWidget();
    gridLayoutWidget->setGeometry(250, 10, 371, 461);
    gridLayoutWidget->setLayout(grille);

    for(int i=0; i<NBDECASIERS; i++){
        lesBoutons[i] = new QPushButton();
        connect(lesBoutons[i], &QPushButton::clicked, this, &InterfaceDesCasiers::onpushButtonMaterielsclicked);
        lesBoutons[i]->setFixedSize(100, 100);
    }
    int compteur = 0;
    for(int etage=0; etage<4; etage++){
        for(int colonne=0; colonne<3; colonne++){
            if(etage != 1 || colonne != 1){
                grille->addWidget(lesBoutons[compteur], etage, colonne);
                compteur++;
                }
            }
        }
    }
    gridLayoutWidget->setParent(this);
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
