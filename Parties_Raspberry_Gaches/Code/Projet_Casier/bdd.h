#ifndef BDD_H
#define BDD_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSettings>
#include <QFileInfo>
#include <QApplication>
#include <QDebug>
#include <QSqlError>

#include "materiel.h"

class BDD
{
public:
    BDD();
    ~BDD();
    bool VerifAdherent(int _numCarte);
    Materiel VerifObjetNonRendu(int _numCarte);
    void MajBDDObjetRendu(int _idObjet);
    Materiel* ListeMaterielEmpreintable();
    void MajBDDObjetEmpreinter(Materiel _objet);
private:
    QSqlDatabase accesBdd;
};

#endif // BDD_H
