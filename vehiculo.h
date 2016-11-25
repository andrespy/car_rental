#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>
#include <QDateTime>
using namespace std;
class Reserva;
class Vehiculo
{
public:
    Vehiculo();
    Vehiculo(string matricula, int capacidad, bool disponible);
    Vehiculo(string matricula, double localizacion[], const  Reserva & reserva, int capacidad, QDateTime tiempoDeUso);
    string getMatricula();
    void setMatricula(string matricula);
    double * getLocalizacion(); // preguntar devolver puntero
    void setLocalizacion(double localizacion[]);
    Reserva * getReserva();
    void setReserva(const Reserva & reserva);
    int getCapacidad();
    void setCapacidad(int capacidad);
    QDateTime getTiempoDeUso();
    void setTiempoDeUso(QDateTime tiempoDeUso);
    Vehiculo & operator=(Vehiculo vehiculo);
    void setDisponible(bool disponible);
    bool getDisponible();
    ~Vehiculo(){}

private:
    string _matricula;
    double _localizacion[2];
    Reserva *_reserva;
    int _capacidad;
    QDateTime _tiempoDeUso;
    bool _disponible;
};

#endif // VEHICULO_H
