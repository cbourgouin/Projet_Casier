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
public:
    Gache(QObject *parent = nullptr);
    void ouvrirCasier(int _numCasier);
private slots:
        void finImpulsion();
        void verifFermeture();
private:
    QTimer *timerImpulsion;
    QTimer *timerVerif;
    int numCasier;
};

#endif // GACHE_H
