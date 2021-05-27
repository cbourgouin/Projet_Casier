/**
  @file fenetredeswitch.cpp
  @brief Implémentation de la classe visuel fenetreDeSwitch
  @author Charly Bourgouin
  @date 05/05/2020
  @details Classe permettant de switch entre les deux interfaces
  */

#include "fenetredeswitch.h"
#include "ui_fenetredeswitch.h"

/**
 * @brief fenetreDeSwitch::fenetreDeSwitch
 * @details lors de la creation permet de construire la fenetre de saisi de
 * numéro de carte ainsi que l'interface de selection de casier
 * @param parent
 * @author Charly Bourgouin
 */
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


/**
 * @brief fenetreDeSwitch::~fenetreDeSwitch
 * @details lors de la destruction, detruit la totalité des fenetres
 * @author Charly Bourgouin
 */
FenetreDeSwitch::~FenetreDeSwitch()
{
    delete ui;
}

/**
 * @brief fenetreDeSwitch::slotDisplayFen
 * @details permet de naviguer entre les multiples widget du programme
 * @param fenIndex index de la fenetre a afficher
 * ( 0 : saisi du numero de carte | 1 : selection de casier )
 * @author Charly Bourgouin
 */
void FenetreDeSwitch::slotDisplayFen(int fenIndex)
{
    if ((fenIndex < 0) || (fenIndex > 1)) {return;}
    stack->setCurrentIndex(fenIndex);
}

/**
 * @brief fenetreDeSwitch::ouvrirCasier
 * @details slots de communication entre les deux fenetre pour ouvrir le casier grace a la position de celui ci
 * @param _x position horizontal du casier
 * @param _y position vertical du casier
 * @author Charly Bourgouin
 */
void FenetreDeSwitch::ouvrirCasier(int _x, int _y)
{
    fen2->ouvrirCasier(_x, _y);
}
