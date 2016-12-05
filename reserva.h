#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include <string>
#include <QDateTime>
#include "plataforma.h"
using namespace std;

class Reserva
{
public:
    Reserva();
    Reserva(const string & id , QDateTime inicio , QDateTime fin , const string &matricula );
    QDateTime getInicio();
    void setInicio(QDateTime inicio);
    QDateTime getFin();
    void setFin(QDateTime fin);

    float precioReserva(QDateTime inicio, QDateTime fin);
    void pideFecha();

    string getId(){return _id;}
    string getMatricula(){return _matricula;}

    Reserva & operator=(Reserva reserva);
    ~Reserva();
private:
    QDateTime _inicio;
    QDateTime _fin;
    string    _id;
    string _matricula;
};

#endif // RESERVA_H
