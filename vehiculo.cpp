#include "vehiculo.h"
#include "reserva.h"
Vehiculo::Vehiculo(string matricula, double localizacion[2], int capacidad, bool disponible)
{
    _matricula = matricula;
    _localizacion[0] = localizacion[0];
    _localizacion[1] = localizacion[1];

    _capacidad = capacidad;
    _disponible = disponible;
}

Vehiculo::Vehiculo()
{
    _matricula = "";
    _localizacion[0] = 0;
    _localizacion[1] = 0;
    _capacidad = 0;
    _disponible = 0;
}
Vehiculo::Vehiculo(string matricula, int capacidad, bool disponible)
{
    _matricula = matricula;
    _localizacion[0] = 0;
    _localizacion[1] = 0;
    _capacidad = capacidad;
    _disponible = disponible;

}
Vehiculo::Vehiculo(const Vehiculo &vehiculo)
{
    _matricula = vehiculo._matricula;
    _capacidad = vehiculo._capacidad;
    _disponible = vehiculo._disponible;
    _localizacion[0]= vehiculo._localizacion[0];
    _localizacion[1]= vehiculo._localizacion[1];
}

string Vehiculo::getMatricula()
{
    return _matricula;
}
void Vehiculo::setMatricula(string matricula)
{
    _matricula = matricula;
}
double * Vehiculo::getLocalizacion() // preguntar devolver puntero
{
    return _localizacion;
}
void Vehiculo::setLocalizacion(double localizacion[])
{
    _localizacion[0] = localizacion[0];
    _localizacion[1] = localizacion[1];
}





int Vehiculo::getCapacidad()
{
    return _capacidad;
}

void Vehiculo::setCapacidad(int capacidad)
{
    _capacidad = capacidad;
}


Vehiculo & Vehiculo::operator=( Vehiculo vehiculo)
{
    _matricula = vehiculo._matricula;
    _localizacion[1] = vehiculo._localizacion[1];
    _localizacion[0] = vehiculo._localizacion[0];
    _capacidad = vehiculo._capacidad;
    _disponible = vehiculo._disponible;
    return *this;
}
void Vehiculo::setDisponible(bool disponible)
{
    _disponible = disponible;
}

bool Vehiculo::getDisponible()
{
    return _disponible;
}


