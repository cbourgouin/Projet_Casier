/**
  @file bdd.h
  @brief Déclaration de la classe Alarme
  @author Charly Bourgouin
  @date 31/05/2021
  */

#ifndef ALARME_H
#define ALARME_H

#include <QObject>
#include <QFileInfo>
#include <QSettings>
#include <QDebug>
#include <QMediaPlayer>

class Alarme : public QObject
{
    Q_OBJECT
public:
    explicit Alarme(QObject *parent = nullptr);
    ~Alarme();
    void demarrerAlarme();
    void arreterAlarme();

signals:

private:
    QString emplacementFichierAudio; /// emplacement du fichier audio de l'alarme
    QMediaPlayer player;
};

#endif // ALARME_H
