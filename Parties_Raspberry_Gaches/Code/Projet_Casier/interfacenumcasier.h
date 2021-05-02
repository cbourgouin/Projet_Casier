#ifndef INTERFACENUMCASIER_H
#define INTERFACENUMCASIER_H

#include <QWidget>
#include <QMessageBox>

#include "bdd.h"
#include "interfacedescasiers.h"
#include "materiel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class interfaceNumCasier; }
QT_END_NAMESPACE

namespace Ui {
class interfaceNumCasier;
}

class interfaceNumCasier : public QWidget
{
    Q_OBJECT

public:
    explicit interfaceNumCasier(QWidget *parent = nullptr);
    ~interfaceNumCasier();

private slots:
    void on_pushButton_clicked();

private:
    Ui::interfaceNumCasier *ui;
};

#endif // INTERFACENUMCASIER_H
