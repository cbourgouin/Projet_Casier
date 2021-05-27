#include "materiel.h"


/**
 * @brief Materiel::Materiel
 * @param _idMateriel id de l'objet
 * @param _nom nom de l'objet
 * @param _positionCasierX position horizontal du casier contenant l'objet
 * @param _positionCasierY position vertical du casier contenant l'objet
 * @author Charly Bourgouin
 */
Materiel::Materiel(int _idMateriel, QString _nom, int _positionCasierX, int _positionCasierY, QString _localisationImage):
    idMateriel(_idMateriel),
    nom(_nom),
    PositionCasierX(_positionCasierX),
    PositionCasierY(_positionCasierY),
    localisationImage(_localisationImage)
{

}


/**
 * @brief Materiel::getPositionCasierX
 * @return
 * @author Charly Bourgouin
 */
int Materiel::getPositionCasierX() const
{
    return PositionCasierX;
}


/**
 * @brief Materiel::setPositionCasierX
 * @param _value
 * @author Charly Bourgouin
 */
void Materiel::setPositionCasierX(int _value)
{
    PositionCasierX = _value;
}


/**
 * @brief Materiel::getPositionCasierY
 * @return
 * @author Charly Bourgouin
 */
int Materiel::getPositionCasierY() const
{
    return PositionCasierY;
}


/**
 * @brief Materiel::setPositionCasierY
 * @param _value
 * @author Charly Bourgouin
 */
void Materiel::setPositionCasierY(int _value)
{
    PositionCasierY = _value;
}

/**
 * @brief Materiel::getLocalisationImage
 * @return
 * @author Charly Bourgouin
 */
QString Materiel::getLocalisationImage() const
{
    return localisationImage;
}

/**
 * @brief Materiel::setLocalisationImage
 * @param value
 * @author Charly Bourgouin
 */
void Materiel::setLocalisationImage(const QString &value)
{
    localisationImage = value;
}

/**
 * @brief Materiel::getNom
 * @return
 * @author Charly Bourgouin
 */
QString Materiel::getNom() const
{
    return nom;
}

/**
 * @brief Materiel::setNom
 * @param _value
 * @author Charly Bourgouin
 */
void Materiel::setNom(const QString _value)
{
    nom = _value;
}

/**
 * @brief Materiel::getIdMateriel
 * @return
 * @author Charly Bourgouin
 */
int Materiel::getIdMateriel() const
{
    return idMateriel;
}

/**
 * @brief Materiel::setIdMateriel
 * @param _value
 * @author Charly Bourgouin
 */
void Materiel::setIdMateriel(int _value)
{
    idMateriel = _value;
}

