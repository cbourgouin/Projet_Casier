#include "interfacedescasiers.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InterfaceDesCasiers w;
    w.show();
    return a.exec();
}
