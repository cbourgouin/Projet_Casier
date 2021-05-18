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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceNumCarte
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *InterfaceNumCarte)
    {
        if (InterfaceNumCarte->objectName().isEmpty())
            InterfaceNumCarte->setObjectName(QStringLiteral("InterfaceNumCarte"));
        InterfaceNumCarte->resize(828, 564);
        widget = new QWidget(InterfaceNumCarte);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 260, 731, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(InterfaceNumCarte);

        QMetaObject::connectSlotsByName(InterfaceNumCarte);
    } // setupUi

    void retranslateUi(QWidget *InterfaceNumCarte)
    {
        InterfaceNumCarte->setWindowTitle(QApplication::translate("InterfaceNumCarte", "Form", nullptr));
        pushButton->setText(QApplication::translate("InterfaceNumCarte", "Valid\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceNumCarte: public Ui_InterfaceNumCarte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACENUMCARTE_H
