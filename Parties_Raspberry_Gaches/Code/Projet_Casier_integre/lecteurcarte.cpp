/**
 * @file lecteurcarte.cpp
 * @author Axel DOMINGOS
 * @details Classe LecteurCarte : Lit le tag NFC et l'affiche
 */

#include "lecteurcarte.h"
#include <QDebug>
//#include "widget.h"
//#include "ui_widget.h"


/**
 * @brief LecteurCarte::LecteurCarte
 * @param parent
 * @details Constructeur de la classe, initialise les attributs
 *          et les connect
 */
LecteurCarte::LecteurCarte(QObject *parent) : QObject(parent)
  , protocole(D0_PIN, D1_PIN)
{
    timer.setSingleShot(true);
    connect(&timer,&QTimer::timeout,this,&LecteurCarte::onTimerTempo_timeout);
    timer.start(500);
}


/**
 * @brief LecteurCarte::~LecteurCarte
 * @details Destructeur de la classe
 */
LecteurCarte::~LecteurCarte()
{

}

/**
 * @brief LecteurCarte::lireTagNFC
 * @return QByteArray code
 * @details Renvoi le code de la carte lue
 */
QByteArray LecteurCarte::lireTagNFC()
{
    QByteArray val = code;
    code = "";
    return val;
}


/**
 * @brief LecteurCarte::onTimerTempo_timeout
 * @details Lance un timer après chaque passage de carte
 */
void LecteurCarte::onTimerTempo_timeout()
{
    int bitLen = protocole.wiegandGetPendingBitCount();
    if (bitLen == 0)
        timer.start(500);
    else
    {
        char data[NBBITMAX];
        bitLen = protocole.wiegandReadData((void *)data, NBBITMAX);
        int bytes = bitLen / 8 + 1;
        qDebug() <<  bitLen << " " << bytes;
        for (int i = 0; i < bytes; i++)
        {
            code.push_front(data[i]);
        }
        emit nouvelle_carte();
        timer.start(500);
    }
}
