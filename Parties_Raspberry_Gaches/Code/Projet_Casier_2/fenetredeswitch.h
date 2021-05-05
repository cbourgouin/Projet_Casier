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

class fenetreDeSwitch : public QMainWindow
{
    Q_OBJECT

public:
    explicit fenetreDeSwitch(QWidget *parent = nullptr);
    ~fenetreDeSwitch();

public slots:
    void slotDisplayFen(int fenIndex);
    void ouvrirCasier(int _x, int  _y);

private:
    Ui::fenetreDeSwitch *ui;
    QStackedWidget *stack;
    InterfaceNumCarte *fen1;
    InterfaceDesCasiers *fen2;
};

#endif // FENETREDESWITCH_H
