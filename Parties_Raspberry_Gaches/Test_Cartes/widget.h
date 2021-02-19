#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ABE_IoPi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    ABElectronics_CPP_Libraries::IoPi bus1;
    ABElectronics_CPP_Libraries::IoPi bus2;
};
#endif // WIDGET_H
