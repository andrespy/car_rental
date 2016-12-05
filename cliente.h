#ifndef CLIENTE_H
#define CLIENTE_H
#include "usuario.h"
#include <math.h>
#include "vehiculo.h"
class Reserva;
//
//
//     **********    CLIENTE    *******
//
//


class Cliente : public Usuario{
public:
    Cliente(Plataforma *plataforma):Usuario(plataforma){}
    Cliente():Usuario(){}
    Cliente(string id, Plataforma *plataforma):Usuario(id, plataforma){}
    //Cliente(string id, int numAbonado):Usuario(id){_numAbonado = numAbonado;}


    double * getLocalizacion();
    void setLocalizacion(double localizacion[]);
    void displayVehiculosDisponibles();
    Vehiculo vehiculoCercano();
    void reservar();
    void historial();
    void menuCliente();
    void displayVehiculoCercano();
    void displayCochesCercanos();
    double distanciaAVehiculo(double * localizacion);

    ~Cliente(){}
protected:
    double _localizacion[2];

};

#endif // CLIENTE_H
