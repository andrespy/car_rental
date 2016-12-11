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
    Vehiculo(string matricula, double localizacion[], int capacidad, bool disponible);
    Vehiculo(const Vehiculo &vehiculo);
    string getMatricula();
    void setMatricula(string matricula);
    double * getLocalizacion(); // preguntar devolver puntero
    void setLocalizacion(double localizacion[]);


    int getCapacidad();
    void setCapacidad(int capacidad);


    Vehiculo & operator=(Vehiculo vehiculo);
    void setDisponible(bool disponible);
    bool getDisponible();
    ~Vehiculo(){}

private:
    string _matricula;
    double _localizacion[2];

    int _capacidad;

    bool _disponible;
};

#endif // VEHICULO_H
