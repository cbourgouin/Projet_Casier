/**
 * @file camera.h
 * @author Axel DOMINGOS
 * @details Classe Camera : Prend des photos
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "lecteurcarte.h"
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QCameraViewfinderSettings>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include "QTimer"
#include "bdd.h"

#define NBPHOTOS 5
#define PRENOM "AXEL"
#define NOM "DOMINGOS"

class Cameras
{
public:
    Cameras();
    void deleteOldFiles();
    void captureImageCasiers();
    void captureImageUtilisateurs();
    QString obtenirNomPrenom();

private slots:
    void onTimerPhoto_timeout();

private:
    QString numCompte;
    QCamera *camera;
    QCamera *camera2;
    QCameraImageCapture *imageCapture;
    QCameraImageCapture *imageCapture2;

    BDD *maBaseDeDonnees;
};

#endif // CAMERA_H
