#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <QDateTime>
using namespace std;
class Plataforma;
class Vehiculo;
class Reserva;
class Usuario
{
public:
    Usuario();
    Usuario(string id, Plataforma *plat);
    Usuario(Plataforma *plat);
    Vehiculo buscar(string matricula);
    Usuario & operator=(Usuario usr);

    string getID();
    void setID(string id);

    //Plataforma * getPlataforma();


    ~Usuario(){}
protected:
    string _id;
    Plataforma *_plataforma;


};















#endif // USUARIO_H
