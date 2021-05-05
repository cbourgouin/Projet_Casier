/**
  @file gache.cpp
  @brief Implémentation de la classe Gache
  @author Charly Bourgouin
  @date 05/05/2020
  @details Classe de m'anipulation des gache du casier
  */

#include "gache.h"
using namespace ABElectronics_CPP_Libraries;

Gache::Gache(QObject *parent) :
    QObject(parent)
{
    timerImpulsion = new QTimer(this);
    timerVerif = new QTimer(this);
    connect(timerImpulsion, &QTimer::timeout, this, &Gache::finImpulsion);
    connect(timerVerif, &QTimer::timeout, this, &Gache::verifFermeture);
}

void Gache::ouvrirCasier(int _numCasier)
{
    numCasier = _numCasier;
        IoPi bus1(0x20);
        IoPi bus2(0x21);
        bus1.set_bus_direction(0x0000);
        bus2.set_bus_direction(0xFFFF);
        bus1.write_bus(0xFFFF);
        bus1.write_pin(_numCasier, 0);
        timerImpulsion->start(500);
}

void Gache::finImpulsion()
{
    timerImpulsion->stop();
    IoPi bus1(0x20);
    bus1.set_bus_direction(0x0000);
    bus1.write_pin(numCasier, 1);
}

void Gache::verifFermeture()
{
    IoPi bus2(0x21);
    bus2.set_bus_direction(0xFFFF);
    if(bus2.read_pin(numCasier) == 1){
        timerVerif->start(300);
    }
    else
    {

    }
}
