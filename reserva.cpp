#include "reserva.h"

Reserva::Reserva()
{

    _inicio = QDateTime();
    _matricula = "";
    _id ="";
    _fin = QDateTime();

}
Reserva::Reserva(const string &id , QDateTime inicio , QDateTime fin , const string & matricula)
{

    QDateTime _inicio(inicio);
    QDateTime _fin(fin);
    _id               =   id;
    _matricula        =   matricula;

}
QDateTime Reserva::getInicio()
{
    return _inicio;
}
void Reserva::setInicio(QDateTime inicio)
{
    _inicio = inicio;
}
QDateTime Reserva::getFin()
{
    return _fin;

}
void Reserva::setFin(QDateTime fin)
{
    _fin = fin;

}


Reserva & Reserva::operator=(Reserva reserva)
{
    _inicio          = reserva._inicio;
    _fin             = reserva._fin;
    _matricula       = reserva._matricula;
    _id              = reserva._id;

    return *this;
}

Reserva::~Reserva()
{

}
