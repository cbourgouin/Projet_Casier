#ifndef INTERFACEDESCASIERS_H
#define INTERFACEDESCASIERS_H

#define NBDECASIERS 11
#define NBDETAGE 4
#define NBDECOLONNE 3

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include "bdd.h"

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
    void setValue(int value);
    
private slots:
    void onpushButtonMaterielsclicked();

private:
    Ui::InterfaceDesCasiers *ui;
    QPushButton* lesBoutons[NBDECASIERS];
    QGridLayout* grille;
    QWidget* gridLayoutWidget;
    int value;

};
#endif // INTERFACEDESCASIERS_H
