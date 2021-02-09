#ifndef INTERFACEDESCASIERS_H
#define INTERFACEDESCASIERS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceDesCasiers; }
QT_END_NAMESPACE

class InterfaceDesCasiers : public QWidget
{
    Q_OBJECT

public:
    InterfaceDesCasiers(QWidget *parent = nullptr);
    ~InterfaceDesCasiers();

private:
    Ui::InterfaceDesCasiers *ui;
};
#endif // INTERFACEDESCASIERS_H
