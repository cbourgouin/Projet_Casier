#ifndef GACHE_H
#define GACHE_H

#include <QObject>
#include <QMessageBox>
#include <QTimer>
#include <stdio.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>
#include "ABE_IoPi.h"

class ControleurDeGache : public QObject
{
    Q_OBJECT

public:
<<<<<<< HEAD
    ControleurDeGache();
    ~ControleurDeGache();
=======
    explicit ControleurDeGache(QObject *parent = nullptr);
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
    void ouvrirCasier(int _numCasier);

private slots:
        void finImpulsion();
        void verifFermeture();

signals:

private:
<<<<<<< HEAD
    QTimer *timerImpulsion; /// Timer pour l'impulsion d'ouverture
    QTimer *timerVerif; /// Timer pour la boucle e verification de la fermeture
    int numCasier; /// Numero du casier
=======
    QTimer *timerImpulsion;
    QTimer *timerVerif;
    ABElectronics_CPP_Libraries::IoPi bus1;
    ABElectronics_CPP_Libraries::IoPi bus2;
    QMessageBox *messageCasierOuvert;
    int numCasier;
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
};

#endif // GACHE_H
