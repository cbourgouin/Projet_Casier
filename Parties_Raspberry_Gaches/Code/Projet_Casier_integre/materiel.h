/**
  @file materiel.h
  @brief Déclaration de la classe Materiel
  @author Charly Bourgouin
  @date 05/05/2020
  */

#ifndef MATERIEL_H
#define MATERIEL_H

#include <QString>

class Materiel
{
public:
    Materiel(int _idMateriel = -1, QString _nom = nullptr, int _positionCasierX = -1, int _positionCasierY = -1, QString _localisationImage = "");

    int getIdMateriel() const;
    void setIdMateriel(int _value);

    QString getNom() const;
    void setNom(const QString _value);

    int getPositionCasierX() const;
    void setPositionCasierX(int _value);

    int getPositionCasierY() const;
    void setPositionCasierY(int _value);

    QString getLocalisationImage() const;
    void setLocalisationImage(const QString &value);

private:
    int idMateriel; /// Id de l'objet
    QString nom; /// nom de l'objet
    int PositionCasierX; /// position horizontal du casier contenant l'objet
    int PositionCasierY; /// position vertical du casier contenant l'objet
    QString localisationImage; /// localisation de l'image de l'objet
};

#endif // MATERIEL_H
