#ifndef MATERIEL_H
#define MATERIEL_H

#include <QString>

class Materiel
{
public:
    Materiel(int _idMateriel = -1, QString _nom = nullptr, int _positionCasierX = -1, int _positionCasierY = -1);

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
    int idMateriel;
    QString nom;
    int PositionCasierX;
    int PositionCasierY;
    QString localisationImage;
};

#endif // MATERIEL_H
