/********************************************************************************
** Form generated from reading UI file 'interfacedescasiers.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEDESCASIERS_H
#define UI_INTERFACEDESCASIERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceDesCasiers
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *InterfaceDesCasiers)
    {
        if (InterfaceDesCasiers->objectName().isEmpty())
            InterfaceDesCasiers->setObjectName(QStringLiteral("InterfaceDesCasiers"));
        InterfaceDesCasiers->resize(800, 480);
        gridLayoutWidget = new QWidget(InterfaceDesCasiers);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(200, 10, 371, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(InterfaceDesCasiers);

        QMetaObject::connectSlotsByName(InterfaceDesCasiers);
    } // setupUi

    void retranslateUi(QWidget *InterfaceDesCasiers)
    {
        InterfaceDesCasiers->setWindowTitle(QApplication::translate("InterfaceDesCasiers", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceDesCasiers: public Ui_InterfaceDesCasiers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEDESCASIERS_H
