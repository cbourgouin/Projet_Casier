/********************************************************************************
** Form generated from reading UI file 'interfacenumcarte.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACENUMCARTE_H
#define UI_INTERFACENUMCARTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceNumCarte
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *InterfaceNumCarte)
    {
        if (InterfaceNumCarte->objectName().isEmpty())
            InterfaceNumCarte->setObjectName(QStringLiteral("InterfaceNumCarte"));
        InterfaceNumCarte->resize(800, 480);
        gridLayoutWidget = new QWidget(InterfaceNumCarte);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 481));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(InterfaceNumCarte);

        QMetaObject::connectSlotsByName(InterfaceNumCarte);
    } // setupUi

    void retranslateUi(QWidget *InterfaceNumCarte)
    {
        InterfaceNumCarte->setWindowTitle(QApplication::translate("InterfaceNumCarte", "Form", nullptr));
        label->setText(QApplication::translate("InterfaceNumCarte", "Passez votre carte sur le scanner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceNumCarte: public Ui_InterfaceNumCarte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACENUMCARTE_H
