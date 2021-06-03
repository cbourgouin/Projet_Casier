/**
  @file alarme.cpp
  @brief Implémentation de la classe Alarme
  @author Charly Bourgouin
  @date 05/05/2020
  @details permettant l'utilisation d'un effet sonore
  */

#include "alarme.h"

/**
 * @brief Alarme::Alarme
 * @param parent
 * @author Charly Bourgouin
 */
Alarme::Alarme(QObject *parent) : QObject(parent)
{
    QString nomFichierIni="Projet_Casier.ini";
    QFileInfo testFichier(nomFichierIni);
    int volume;

    if(testFichier.exists() && testFichier.isFile())
    {
        QSettings paramsSocket(nomFichierIni, QSettings::IniFormat);
        emplacementFichierAudio = paramsSocket.value("ALARME/positionson").toString();
        volume = paramsSocket.value("ALARME/volume").toInt();
        player.setMedia(QUrl("qrc:/img/alarme-de-reveil-standard-son.mp3"));//qrc:/img/alarme-de-reveil-standard-son.mp3
        player.setVolume(volume);
    }
    else
    {
        qDebug()<<"fichier ini non valide";
    }
}


/**
 * @brief Alarme::~Alarme
 * @author Charly Bourgouin
 */
Alarme::~Alarme()
{

}


/**
 * @brief Alarme::demarrerAlarme
 * @details Démarrer l'alarme
 * @author Charly Bourgouin
 */
void Alarme::demarrerAlarme()
{
    player.play();
}
/**
 * @brief Alarme::arreterAlarme
 * @details Arréter l'alarme
 * @author Charly Bourgouin
 */
void Alarme::arreterAlarme()
{
    player.stop();
}
