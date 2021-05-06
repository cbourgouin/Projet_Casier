/**
  @file fenetredeswitch.cpp
  @brief Implémentation de la classe visuel fenetreDeSwitch
  @author Charly Bourgouin
  @date 05/05/2020
  @details Classe permettant de switch entre les deux interfaces
  */

#include "fenetredeswitch.h"
#include "ui_fenetredeswitch.h"

FenetreDeSwitch::FenetreDeSwitch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fenetreDeSwitch)
{
    ui->setupUi(this);
    stack = new QStackedWidget(this);
    fen1 = new InterfaceNumCarte(this);
    fen2 = new InterfaceDesCasiers(this);

    stack->addWidget(fen1);
    stack->addWidget(fen2);

    this->setCentralWidget(stack);
    stack->setCurrentIndex(0);

    connect(fen1, SIGNAL(askDisplayFen(int)), this, SLOT(slotDisplayFen(int)));
    connect(fen2, SIGNAL(askDisplayFen(int)), this, SLOT(slotDisplayFen(int)));
    connect(fen1, SIGNAL(ouvrirCasier(int , int)), this, SLOT(ouvrirCasier(int, int)));
}

FenetreDeSwitch::~FenetreDeSwitch()
{
    delete ui;
}

void FenetreDeSwitch::slotDisplayFen(int fenIndex)
{
    if ((fenIndex < 0) || (fenIndex > 1)) {return;}
    stack->setCurrentIndex(fenIndex);
}

void FenetreDeSwitch::ouvrirCasier(int _x, int _y)
{
    fen2->ouvrirCasier(_x, _y);
}
