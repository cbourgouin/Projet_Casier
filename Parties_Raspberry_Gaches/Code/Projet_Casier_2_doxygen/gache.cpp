#include "gache.h"
#include <QDebug>
using namespace ABElectronics_CPP_Libraries;

<<<<<<< HEAD
/**
 * @brief Gache::Gache
 * @author Charly Bourgouin
 */
Gache::Gache()
{
    timerImpulsion = new QTimer();
    timerVerif = new QTimer();
=======
Gache::Gache(QObject *parent)
  : QObject(parent)
  , bus1(0x20)
  , bus2(0x21)
{
    bus1.set_bus_direction(0x0000);
    bus1.write_bus(0xFFFF);
    bus2.set_bus_direction(0xFFFF);
    timerImpulsion = new QTimer();
    timerVerif = new QTimer(this);
    timerImpulsion->setSingleShot(true);

>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
    connect(timerImpulsion, &QTimer::timeout, this, &Gache::finImpulsion);
    connect(timerVerif, &QTimer::timeout, this, &Gache::verifFermeture);
}

/**
 * @brief Gache::~Gache
 * @author Charly Bourgouin
 */
Gache::~Gache()
{
    delete timerImpulsion;
    delete timerVerif;
}

/**
 * @brief Gache::ouvrirCasier
 * @details permet l'ouverture du casier ciblé
 * @param _numCasier numéro du casier a ouvrir
 * @author Charly Bourgouin
 */
void Gache::ouvrirCasier(int _numCasier)
{
    numCasier = _numCasier;
<<<<<<< HEAD
        IoPi bus1(0x20);
        bus1.set_bus_direction(0x0000);
        bus1.write_bus(0xFFFF);
        bus1.write_pin(_numCasier, 0);
        timerImpulsion->start(500);
=======
    bus1.write_pin(numCasier, 0);
    qDebug()<<"avant lancement timer";
    timerImpulsion->start(500);
    qDebug()<<"apres lancement timer";

>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
}

/**
 * @brief Gache::finImpulsion
 * @details slots permettant de mettre fin a l'impulsion pour ouvrir le casier
 * @author Charly Bourgouin
 */
void Gache::finImpulsion()
{
    qDebug()<<"dans timeout timer";

    bus1.write_pin(numCasier, 1);
    messageCasierOuvert = new QMessageBox();
    messageCasierOuvert->setText("Casier ouvert !");
    messageCasierOuvert->exec();
    timerVerif->start(100);
}

/**
 * @brief Gache::verifFermetur
 * @details slots permettant de verifier le de manière periodique la fermeture du casier
 * @author Charly Bourgouin
 */
void Gache::verifFermeture()
{
    timerVerif->stop();
<<<<<<< HEAD
    IoPi bus2(0x21);
    bus2.set_bus_direction(0xFFFF);
=======
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
    if(bus2.read_pin(numCasier) == 1){
        timerVerif->start(100);
    }
    else
    {
        messageCasierOuvert->hide();
        delete messageCasierOuvert;
    }
}
