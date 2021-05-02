#include "gache.h"

Gache::Gache()
{
    bus1 = new ABElectronics_CPP_Libraries::IoPi(0x20);
    bus2 = new ABElectronics_CPP_Libraries::IoPi(0x21);
    bus1->set_bus_direction(0);
    bus2->set_bus_direction(1);
}

void Gache::ouvrirCasier(int _numCasier)
{
    bus1->write_pin(_numCasier, 1);
    QMessageBox message;
    message.setText("Le casier est ouvert");
    message.show();

    while(!bus2->read_pin(_numCasier)){

    }
    message.hide();
}
