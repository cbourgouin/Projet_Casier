#include "controleurdegache.h"
#include <QDebug>
using namespace ABElectronics_CPP_Libraries;

ControleurDeGache::ControleurDeGache(QObject *parent)
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

    connect(timerImpulsion, &QTimer::timeout, this, &ControleurDeGache::finImpulsion);
    connect(timerVerif, &QTimer::timeout, this, &ControleurDeGache::verifFermeture);
}

void ControleurDeGache::ouvrirCasier(int _numCasier)
{
    numCasier = _numCasier;
    bus1.write_pin(numCasier, 0);
    qDebug()<<"avant lancement timer";
    timerImpulsion->start(500);
    qDebug()<<"apres lancement timer";

}

void ControleurDeGache::finImpulsion()
{
    qDebug()<<"dans timeout timer";

    bus1.write_pin(numCasier, 1);
    messageCasierOuvert = new QMessageBox();
    messageCasierOuvert->setText("Casier ouvert !");
    messageCasierOuvert->exec();
    timerVerif->start(100);
}

void ControleurDeGache::verifFermeture()
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
