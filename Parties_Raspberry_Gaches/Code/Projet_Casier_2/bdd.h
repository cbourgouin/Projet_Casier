/**
  @file bdd.h
  @brief Déclaration de la classe BDD
  @author Charly Bourgouin
  @date 05/05/2020
  */

#ifndef BDD_H
#define BDD_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSettings>
#include <QFileInfo>
#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <vector>

#include "materiel.h"

class BDD
{
public:
    BDD();
    ~BDD();
    bool VerifAdherent(int _numCarte);
    Materiel *VerifObjetNonRendu(int _numCarte);
    void MajBDDObjetRendu(int _idObjet);
    std::vector<Materiel> ListeMaterielEmpreintable();
    void MajBDDObjetEmpreinter(Materiel _objet, int _numCarte);
private:
    QSqlDatabase accesBdd;
};

#endif // BDD_H
