#include "controleurdegache.h"
#include <QDebug>
using namespace ABElectronics_CPP_Libraries;

/**
 * @brief ControleurDeGache::ControleurDeGache
 * @param parent
 */
ControleurDeGache::ControleurDeGache(QObject *parent)
  : QObject(parent)
  , bus1(0x20)
  , bus2(0x21)
{
    bus1.set_bus_direction(0x0000);    
    bus2.set_bus_direction(0xFFFF);
    bus1.write_bus(0xFFFF);
    timerImpulsion = new QTimer();
    timerVerif = new QTimer();
    timerImpulsion->setSingleShot(true);

    connect(timerImpulsion, &QTimer::timeout, this, &ControleurDeGache::on_timerImpulsion_timeout);
    connect(timerVerif, &QTimer::timeout, this, &ControleurDeGache::onTimerVerif_timeout);
}

/**
 * @brief ControleurDeGache::ouvrirCasier
 * @details permet l'ouverture du casier ciblé
 * @param _numCasier numéro du casier a ouvrir
 * @author Charly Bourgouin
 */
void ControleurDeGache::ouvrirCasier(int _numCasier)
{
    numCasier = _numCasier;
    bus1.write_pin(numCasier, 0);
    qDebug()<<"avant lancement timer";
    timerImpulsion->start(500);
    qDebug()<<"apres lancement timer";

}

/**
 * @brief ControleurDeGache::on_timerImpulsion_timeout
 * @details slots permettant de mettre fin a l'impulsion pour ouvrir le casier
 * @author Charly Bourgouin
 */
void ControleurDeGache::on_timerImpulsion_timeout()
{
    qDebug()<<"dans timeout timer";

    bus1.write_pin(numCasier, 1);
    messageCasierOuvert = new QMessageBox();
    messageCasierOuvert->setText("Casier ouvert !");
    messageCasierOuvert->exec();
    timerVerif->start(100);
}

/**
 * @brief ControleurDeGache::onTimerVerif_timeout
 * @details slots permettant de verifier le de manière periodique la fermeture du casier
 * @author Charly Bourgouin
 */
void ControleurDeGache::onTimerVerif_timeout()
{
    timerVerif->stop();
    if(bus2.read_pin(numCasier) == 1){
        timerVerif->start(100);
    }
    else
    {
        messageCasierOuvert->hide();
        delete messageCasierOuvert;
    }
}
