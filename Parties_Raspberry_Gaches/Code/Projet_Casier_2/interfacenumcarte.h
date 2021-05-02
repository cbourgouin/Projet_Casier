#ifndef INTERFACENUMCARTE_H
#define INTERFACENUMCARTE_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <qstackedwidget.h>

#include "bdd.h"
#include "materiel.h"
#include "gache.h"

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
       void on_pushButton_clicked();

   signals:
       void askDisplayFen(int value);
       void ouvrirCasier(int casierX, int casierY);

private:
    Ui::InterfaceNumCarte *ui;
    QStackedWidget *stack;
    QWidget *fenetreDeSwitch;

};

#endif // INTERFACENUMCARTE_H
