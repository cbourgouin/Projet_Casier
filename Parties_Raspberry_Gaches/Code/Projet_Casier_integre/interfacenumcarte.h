/**
  @file interfacenumcarte.h
  @brief Déclaration de la classe visuel InterfaceNumCarte
  @author Charly Bourgouin
  @date 05/05/2020
  */

#ifndef INTERFACENUMCARTE_H
#define INTERFACENUMCARTE_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <qstackedwidget.h>

#include "bdd.h"
#include "materiel.h"
#include "controleurdegache.h"
#include "cameras.h"
#include "lecteurcarte.h"

namespace Ui {
class InterfaceNumCarte;
}

class InterfaceNumCarte : public QWidget
{
    Q_OBJECT

   public:
       explicit InterfaceNumCarte(QWidget *parent = nullptr);
       ~InterfaceNumCarte();

   private slots:
       void on_LC_nouvelle_carte();

   signals:
       void askDisplayFen(QString _numCarte);
       void ouvrirCasier(int _casierX, int _casierY);

private:
    LecteurCarte LC;
    QString numCarte;
    QStackedWidget *stack;
    QWidget *fenetreDeSwitch;
    Ui::InterfaceNumCarte *ui;
};

#endif // INTERFACENUMCARTE_H
