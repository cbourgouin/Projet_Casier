#ifndef GACHE_H
#define GACHE_H

#include <QMessageBox>

#include "ABE_IoPi.h"

class Gache
{
public:
    Gache();
    void ouvrirCasier(int _numCasier);
private:
    ABElectronics_CPP_Libraries::IoPi *bus1;
    ABElectronics_CPP_Libraries::IoPi *bus2;
};

#endif // GACHE_H
