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
    Cliente(string id, Plataforma *plataforma):Usuario(id, plataforma){}
    //Cliente(string id, int numAbonado):Usuario(id){_numAbonado = numAbonado;}


    double * getLocalizacion();
    void setLocalizacion(double localizacion[]);
    double * localizarVehiculos();
    Vehiculo vehiculoCercano();
    void reservar();
    Reserva * historial();
    void menuCliente();
    void displayVehiculoCercano();
    void displayCochesCercanos();
    double distanciaAVehiculo(double * localizacion);
    ~Cliente(){}
protected:
    int _id;
    double _localizacion[2];
};

#endif // CLIENTE_H
