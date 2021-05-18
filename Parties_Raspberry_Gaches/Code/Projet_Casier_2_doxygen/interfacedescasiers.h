/**
  @file interfacedescasier.h
  @brief Déclaration de la classe visuel InterfaceDesCasiers
  @author Charly Bourgouin
  @date 05/05/2020
  */

#ifndef INTERFACEDESCASIERS_H
#define INTERFACEDESCASIERS_H

#define NBDECASIERS 11
#define NBDETAGE 4
#define NBDECOLONNE 3

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLayoutItem>
#include <vector>
//#include <QWebEngineView>

#include "bdd.h"
#include "gache.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceDesCasiers; }
QT_END_NAMESPACE

class InterfaceDesCasiers : public QWidget
{
    Q_OBJECT

public:
    InterfaceDesCasiers(QWidget *parent = nullptr);
    ~InterfaceDesCasiers();
    void ouvrirCasier(int _x, int _y);

private slots:
    void onpushButtonMaterielsclicked();

signals:
    void askDisplayFen(int value);

private:
    Ui::InterfaceDesCasiers *ui;
    int nbCasierX; /// Nombre de colonne de casiers
    int nbCasierY; /// Nombre de ligne de casiers
    int nbCasier; /// Nombre de casiers
    QPushButton* lesBoutons[NBDECASIERS]; /// Boutons de l'interface
    QGridLayout* grille;
    QWidget* gridLayoutWidget;
<<<<<<< HEAD
    Gache *lesGache; /// Class de manipulatio de classe
=======
    Gache lesGaches;
    int value;
>>>>>>> 3921db3ff0712f26367d9a4cb117bdc9ced18919
    void miseAJourInterface();

};
#endif // INTERFACEDESCASIERS_H
