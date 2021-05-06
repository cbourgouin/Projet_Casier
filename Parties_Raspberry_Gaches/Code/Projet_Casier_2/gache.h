/**
  @file gache.h
  @brief Déclaration de la classe Gache
  @author Charly Bourgouin
  @date 05/05/2020
  */

#ifndef GACHE_H
#define GACHE_H

#include <QMessageBox>
#include <QTimer>
#include <stdio.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>
#include <QObject>
#include "ABE_IoPi.h"

class Gache : public QObject
{
    Q_OBJECT

public:
    Gache(QObject *parent = nullptr);
    void ouvrirCasier(int _numCasier);

private slots:
        void finImpulsion();
        void verifFermeture();

signals:

private:
    QTimer *timerImpulsion;
    QTimer *timerVerif;
    ABElectronics_CPP_Libraries::IoPi bus1;
    ABElectronics_CPP_Libraries::IoPi bus2;
    QMessageBox *messageCasierOuvert;
    int numCasier;
};

#endif // GACHE_H
