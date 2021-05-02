#include "fenetredeswitch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fenetreDeSwitch w;
    w.show();
    return a.exec();
}
