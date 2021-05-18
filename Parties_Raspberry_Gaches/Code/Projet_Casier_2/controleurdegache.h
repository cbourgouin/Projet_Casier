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
    explicit ControleurDeGache(QObject *parent = nullptr);
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
