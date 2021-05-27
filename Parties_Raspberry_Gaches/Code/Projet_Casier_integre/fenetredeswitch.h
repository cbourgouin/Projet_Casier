/**
  @file fenetredeswitch.h
  @brief Déclaration de la classe visuel fenetreDeSwitch
  @author Charly Bourgouin
  @date 05/05/2020
  */

#ifndef FENETREDESWITCH_H
#define FENETREDESWITCH_H

#include <QMainWindow>
#include <QStackedWidget>

#include "interfacedescasiers.h"
#include "interfacenumcarte.h"

namespace Ui {
class fenetreDeSwitch;
}

class FenetreDeSwitch : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreDeSwitch(QWidget *parent = nullptr);
    ~FenetreDeSwitch();

public slots:
    void slotDisplayFen1();
    void slotDisplayFen2(QString _numCarte);
    void ouvrirCasier(int _x, int  _y);

private:
    Ui::fenetreDeSwitch *ui;
    QStackedWidget *stack; /// Stack des widgets a afficher
    InterfaceNumCarte *fen1; /// Affichage des boutons de selection des casiers
    InterfaceDesCasiers *fen2; /// Affichage d'entrée du numero de la carte de l'utilisateur
};

#endif // FENETREDESWITCH_H
