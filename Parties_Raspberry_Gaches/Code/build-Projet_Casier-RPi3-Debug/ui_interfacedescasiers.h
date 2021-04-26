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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceDesCasiers
{
public:

    void setupUi(QWidget *InterfaceDesCasiers)
    {
        if (InterfaceDesCasiers->objectName().isEmpty())
            InterfaceDesCasiers->setObjectName(QStringLiteral("InterfaceDesCasiers"));
        InterfaceDesCasiers->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InterfaceDesCasiers->sizePolicy().hasHeightForWidth());
        InterfaceDesCasiers->setSizePolicy(sizePolicy);
        InterfaceDesCasiers->setMinimumSize(QSize(800, 480));
        InterfaceDesCasiers->setMaximumSize(QSize(800, 480));
        InterfaceDesCasiers->setSizeIncrement(QSize(800, 480));

        retranslateUi(InterfaceDesCasiers);

        QMetaObject::connectSlotsByName(InterfaceDesCasiers);
    } // setupUi

    void retranslateUi(QWidget *InterfaceDesCasiers)
    {
        InterfaceDesCasiers->setWindowTitle(QApplication::translate("InterfaceDesCasiers", "InterfaceDesCasiers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceDesCasiers: public Ui_InterfaceDesCasiers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEDESCASIERS_H
