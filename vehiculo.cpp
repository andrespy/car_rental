#include "vehiculo.h"
#include "reserva.h"
Vehiculo::Vehiculo(string matricula, double localizacion[2], const Reserva &reserva, int capacidad, QDateTime tiempoDeUso)
{
    _matricula = matricula;
    _localizacion[0] = localizacion[0];
    _localizacion[1] = localizacion[1];
    *_reserva = reserva;
    _capacidad = capacidad;
    _tiempoDeUso = tiempoDeUso;
}

Vehiculo::Vehiculo()
{
    _matricula = "";
    _localizacion[0] = 0;
    _localizacion[1] = 0;
    *_reserva = Reserva();
    _capacidad = 0;
    _tiempoDeUso = QDateTime();
}
Vehiculo::Vehiculo(string matricula, int capacidad, bool disponible)
{
    _matricula = matricula;
    _localizacion[0] = 0;
    _localizacion[1] = 0;
    Reserva *_reserva();
    _capacidad = capacidad;
    _tiempoDeUso = QDateTime();
    _disponible = disponible;

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

Reserva * Vehiculo::getReserva()
{
    return _reserva;
}

void Vehiculo::setReserva(const Reserva & reserva)
{
    *_reserva = reserva;
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
    _reserva = vehiculo._reserva;
    _capacidad = vehiculo._capacidad;
    _tiempoDeUso = vehiculo._tiempoDeUso;
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


