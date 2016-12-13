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
    Usuario(const Usuario &usuario);
    Usuario & operator=(Usuario usr);
    Plataforma* getPlataforma();

    string getID();
    void setID(string id);

    ~Usuario(){}
protected:
    string _id;
    Plataforma *_plataforma;


};















#endif // USUARIO_H
