/**
 * @file camera.cpp
 * @author Axel DOMINGOS
 * @details Classe Camera : Prend des photos
 */

#include "cameras.h"
//#include "widget.h"
//#include "ui_widget.h"
//#include "wiegand_c.h"
#include <QSettings>


/**
 * @brief Camera::Camera
 * @details Constructeur de la classe, instancie les caméras
 *          en mode capture d'image
 */
Cameras::Cameras()
{
    //connect(&timerPhoto,&QTimer::timeout,this,&Cameras::onTimerPhoto_timeout);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    qDebug() << " ";
    qDebug() << "cameras disponibles : ";
    camera = new QCamera(cameras.at(0));
    //camera->setViewfinderSettings(pictureSettings);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    imageCapture = new QCameraImageCapture(camera);
    camera->start();
    qDebug() <<cameras.at(0);

    qDebug() << " ";
    camera2 = new QCamera(cameras.at(1));
    //camera2->setViewfinderSettings(pictureSettings);
    camera2->setCaptureMode(QCamera::CaptureStillImage);
    imageCapture2 = new QCameraImageCapture(camera2);
    camera2->start();
    qDebug() << cameras.at(1);



    for(const QCameraInfo &cameraInfo : cameras)
    {
        qDebug() << " ";
        qDebug() << "nom de la camera : " << cameraInfo.deviceName();
        qDebug() << "description de la caméra : "<<cameraInfo.description();
        qDebug() << "état de la caméra : "<<cameraInfo.isNull();   //retourne vrai si la caméra est invalide
    }
    qDebug() << " ";
    qDebug() << "camera par default : " << QCameraInfo::defaultCamera();
    qDebug() << " ";
}

QDateTime now = QDateTime::currentDateTime();   //date/heure actuelle
QString timestamp = now.toString(QLatin1String("ddMMyyyy-hhmmss"));   //format de la date
QSettings settings ("Chemin.ini", QSettings::IniFormat);
QString chemin = settings.value("Camera/chemin").toString();   //chemin stockage des images
const QList<QCameraInfo> cameras = QCameraInfo::availableCameras(); //liste des cameras
QCameraViewfinderSettings pictureSettings;   //paramètre photos


/**
 * @brief Camera::deleteOldFiles
 * @details Supprime les photos prises automatiquement au bout de 2 semaines
 *          à l'aide d'un filtre pour le nom des photos
 */
void Cameras::deleteOldFiles()
{

}


/**
 * @brief Camera::captureImageCasiers
 * @details Prend des photos des casiers et renomme les photos
 *          avec le nom, le prenom de l'emprunteur et la date
 */
void Cameras::captureImageCasiers()
{
    pictureSettings.setResolution(1280, 720);
    // choix de la caméra
    if (cameras.size() > 0) {
        camera = new QCamera(cameras.at(0));
        if (camera) {
            camera->setCaptureMode(QCamera::CaptureViewfinder);
            // change la resolution a 1280x720
            camera->setViewfinderSettings(pictureSettings);
            QString filename = QString::fromLatin1("%1%2-%3-%4-CASIERS.jpg").arg(chemin).arg(NOM).arg(PRENOM).arg(timestamp);
           imageCapture->capture(filename);
            qDebug() << "Photo casier";
        }
    }
}


/**
 * @brief Camera::captureImageUtilisateurs
 * @details Prend des photos des utilisateurs et renomme les photos
 *          avec le nom, le prenom de l'emprunteur et la date
 */
void Cameras::captureImageUtilisateurs()
{
    pictureSettings.setResolution(1280, 720);
    // choix de la caméra
    if (cameras.size() > 0) {
        camera2 = new QCamera(cameras.at(1));
        if (camera2) {
            camera2->setCaptureMode(QCamera::CaptureViewfinder);
            // change la resolution a 1280x720 et le nom de la photo
            camera2->setViewfinderSettings(pictureSettings);
            QString filename = QString::fromLatin1("%1%2-%3-%4-UTILISATEURS.jpg").arg(chemin).arg(NOM).arg(PRENOM).arg(timestamp);
            //for(int indice=0; indice<NBPHOTOS; indice++)
            //{
                imageCapture2->capture(filename);
                qDebug() << "Photo utilisateur";
            //}
            //timerPhoto.start(1000);
        }
    }
}

void Cameras::onTimerPhoto_timeout()
{
    //timerPhoto.stop();
}





