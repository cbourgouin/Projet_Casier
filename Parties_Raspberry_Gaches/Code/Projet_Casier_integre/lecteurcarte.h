/**
 * @file lecteurcarte.h
 * @author Axel DOMINGOS
 * @details Classe LecteurCarte : Lit le tag NFC et l'affiche
 */

#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

#include <QObject>
#include "QTimer"
#include "wiegand.h"
#include "cameras.h"

#define NBBITMAX 100


class LecteurCarte : public QObject
{
    Q_OBJECT
public:
    explicit LecteurCarte(QObject *parent = nullptr);
    ~LecteurCarte();
    QByteArray lireTagNFC();

private slots:
    void onTimerTempo_timeout();

private:
    QTimer timer;
    QByteArray code;
    Wiegand protocole;

signals:
    void nouvelle_carte();
};

#endif // LECTEURCARTE_H
