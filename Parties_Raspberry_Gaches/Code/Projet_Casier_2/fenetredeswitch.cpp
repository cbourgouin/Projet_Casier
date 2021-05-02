#include "fenetredeswitch.h"
#include "ui_fenetredeswitch.h"

fenetreDeSwitch::fenetreDeSwitch(QWidget *parent) :
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

fenetreDeSwitch::~fenetreDeSwitch()
{
    delete ui;
}

void fenetreDeSwitch::slotDisplayFen(int fenIndex)
{
    if ((fenIndex < 0) || (fenIndex > 1)) {return;}
    stack->setCurrentIndex(fenIndex);
}

void fenetreDeSwitch::ouvrirCasier(int _x, int _y)
{
    fen2->ouvrirCasier(_x, _y);
}
