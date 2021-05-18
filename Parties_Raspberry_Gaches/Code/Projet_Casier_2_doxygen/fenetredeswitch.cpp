/**
  @file fenetredeswitch.cpp
  @brief Implémentation de la classe visuel fenetreDeSwitch
  @author Charly Bourgouin
  @date 05/05/2020
  @details Classe permettant de switch entre les deux interfaces
  */

#include "fenetredeswitch.h"
#include "ui_fenetredeswitch.h"

<<<<<<< HEAD
/**
 * @brief fenetreDeSwitch::fenetreDeSwitch
 * @details lors de la creation permet de construire la fenetre de saisi de
 * numéro de carte ainsi que l'interface de selection de casier
 * @param parent
 * @author Charly Bourgouin
 */
fenetreDeSwitch::fenetreDeSwitch(QWidget *parent) :
=======
FenetreDeSwitch::FenetreDeSwitch(QWidget *parent) :
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
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

<<<<<<< HEAD
/**
 * @brief fenetreDeSwitch::~fenetreDeSwitch
 * @details lors de la destruction, detruit la totalité des fenetres
 * @author Charly Bourgouin
 */
fenetreDeSwitch::~fenetreDeSwitch()
=======
FenetreDeSwitch::~FenetreDeSwitch()
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
{
    delete ui;
    delete stack;
    delete fen1;
    delete fen2;
}

<<<<<<< HEAD
/**
 * @brief fenetreDeSwitch::slotDisplayFen
 * @details permet de naviguer entre les multiples widget du programme
 * @param fenIndex index de la fenetre a afficher
 * ( 0 : saisi du numero de carte | 1 : selection de casier )
 * @author Charly Bourgouin
 */
void fenetreDeSwitch::slotDisplayFen(int fenIndex)
=======
void FenetreDeSwitch::slotDisplayFen(int fenIndex)
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
{
    if ((fenIndex < 0) || (fenIndex > 1)) {return;}
    stack->setCurrentIndex(fenIndex);
}

<<<<<<< HEAD
/**
 * @brief fenetreDeSwitch::ouvrirCasier
 * @details slots de communication entre les deux fenetre pour ouvrir le casier grace a la position de celui ci
 * @param _x position horizontal du casier
 * @param _y position vertical du casier
 * @author Charly Bourgouin
 */
void fenetreDeSwitch::ouvrirCasier(int _x, int _y)
=======
void FenetreDeSwitch::ouvrirCasier(int _x, int _y)
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
{
    fen2->ouvrirCasier(_x, _y);
}
