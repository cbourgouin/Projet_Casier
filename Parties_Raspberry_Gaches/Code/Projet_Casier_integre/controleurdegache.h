/**
  @file bdd.h
  @brief Déclaration de la classe ControleurDeGache
  @author Charly Bourgouin
  @date 31/05/2021
  */

#ifndef GACHE_H
#define GACHE_H

#include <QObject>
#include <QMessageBox>
#include <QTimer>
#include <stdio.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>

#include "cameras.h"
#include "ABE_IoPi.h"
#include "alarme.h"

class ControleurDeGache : public QObject
{
    Q_OBJECT

public:
    explicit ControleurDeGache(QObject *parent = nullptr);
    void ouvrirCasier(int _numCasier);

private slots:
        void onTimerImpulsion_timeout();
        void onTimerVerif_timeout();

signals:
        void casierFerme();

private:
    int numCasier; /// Numero du casier
    Cameras camera;
    QTimer timerImpulsion; /// Timer pour l'impulsion d'ouverture
    QTimer timerVerif; /// Timer pour la boucle e verification de la fermeture
    QMessageBox *messageCasierOuvert; 
    ABElectronics_CPP_Libraries::IoPi bus1;
    ABElectronics_CPP_Libraries::IoPi bus2;
    Alarme *alm;

};

#endif // GACHE_H
