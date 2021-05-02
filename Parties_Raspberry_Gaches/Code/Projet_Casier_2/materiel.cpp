#include "materiel.h"

Materiel::Materiel(int _idMateriel, QString _nom, int _positionCasierX, int _positionCasierY):
    idMateriel(_idMateriel),
    nom(_nom),
    PositionCasierX(_positionCasierX),
    PositionCasierY(_positionCasierY)
{

}

int Materiel::getPositionCasierX() const
{
    return PositionCasierX;
}

void Materiel::setPositionCasierX(int _value)
{
    PositionCasierX = _value;
}

int Materiel::getPositionCasierY() const
{
    return PositionCasierY;
}

void Materiel::setPositionCasierY(int _value)
{
    PositionCasierY = _value;
}

QString Materiel::getLocalisationImage() const
{
    return localisationImage;
}

void Materiel::setLocalisationImage(const QString &value)
{
    localisationImage = value;
}

QString Materiel::getNom() const
{
    return nom;
}

void Materiel::setNom(const QString _value)
{
    nom = _value;
}

int Materiel::getIdMateriel() const
{
    return idMateriel;
}

void Materiel::setIdMateriel(int _value)
{
    idMateriel = _value;
}

