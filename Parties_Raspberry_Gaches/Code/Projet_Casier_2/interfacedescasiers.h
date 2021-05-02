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

    int getValue() const;
    void setValue(int _value);
    void ouvrirCasier(int _x, int _y);

private slots:
    void onpushButtonMaterielsclicked();

private:
    Ui::InterfaceDesCasiers *ui;
    int nbCasierX;
    int nbCasierY;
    QPushButton* lesBoutons[NBDECASIERS];
    QGridLayout* grille;
    QWidget* gridLayoutWidget;
    Gache *lesGache;
    int value;
    void miseAJourInterface();

};
#endif // INTERFACEDESCASIERS_H
