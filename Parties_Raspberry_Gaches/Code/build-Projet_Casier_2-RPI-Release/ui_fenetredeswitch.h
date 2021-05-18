/********************************************************************************
** Form generated from reading UI file 'fenetredeswitch.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREDESWITCH_H
#define UI_FENETREDESWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fenetreDeSwitch
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *fenetreDeSwitch)
    {
        if (fenetreDeSwitch->objectName().isEmpty())
            fenetreDeSwitch->setObjectName(QStringLiteral("fenetreDeSwitch"));
        fenetreDeSwitch->resize(800, 600);
        menubar = new QMenuBar(fenetreDeSwitch);
        menubar->setObjectName(QStringLiteral("menubar"));
        fenetreDeSwitch->setMenuBar(menubar);
        centralwidget = new QWidget(fenetreDeSwitch);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        fenetreDeSwitch->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(fenetreDeSwitch);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        fenetreDeSwitch->setStatusBar(statusbar);

        retranslateUi(fenetreDeSwitch);

        QMetaObject::connectSlotsByName(fenetreDeSwitch);
    } // setupUi

    void retranslateUi(QMainWindow *fenetreDeSwitch)
    {
        fenetreDeSwitch->setWindowTitle(QApplication::translate("fenetreDeSwitch", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fenetreDeSwitch: public Ui_fenetreDeSwitch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREDESWITCH_H
