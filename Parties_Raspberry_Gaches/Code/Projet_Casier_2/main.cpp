#include "fenetredeswitch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetreDeSwitch w;
    w.show();
    return a.exec();
}
