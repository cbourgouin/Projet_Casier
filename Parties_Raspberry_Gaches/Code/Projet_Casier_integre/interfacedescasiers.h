/**
  @file interfacedescasier.h
  @brief Déclaration de la classe visuel InterfaceDesCasiers
  @author Charly Bourgouin
  @date 05/05/2020
  */

#ifndef INTERFACEDESCASIERS_H
#define INTERFACEDESCASIERS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLayoutItem>
#include <vector>

#include "bdd.h"
#include "controleurdegache.h"

enum Protocol { restitution, empreint };

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
    void setNumCarte(QString _numCarte);

private slots:
    void onpushButtonMaterielsclicked();
    void onCasierFerme();

signals:
    void askDisplayFen();

private:    
    int nbCasierX;
    int nbCasierY;
    int nbCasier;
    int numCasier;
    int positionXObjetRendu;
    int positionYObjetRendu;
    Protocol pc;
    QString numCarte;
    QVector<Materiel> listeMateriel;
    QVector<QPushButton*> lesBoutons;
    QGridLayout* grille;
    QPushButton* leBouttonDeLObjetRendu;
    ControleurDeGache controlDeGache;
    BDD *maBaseDeDonnees;
    Ui::InterfaceDesCasiers *ui;

    void miseAJourInterface();

};
#endif // INTERFACEDESCASIERS_H
