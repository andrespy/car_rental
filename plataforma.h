#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <QDateTime>
#include "usuario.h"
#include "vehiculo.h"
#include "administrador.h"
#include "cliente.h"
#include "vip.h"
#include "reserva.h"
using namespace std;


class Plataforma
{
public:
    Plataforma();


    void menu();





    void setUsuario(const Usuario &usuario);
    void setVehiculo(const Vehiculo &vehiculo);

    //list::iterator buscarUsuario(string id);


    void append(Vehiculo vehiculo);
    void append(Usuario usuario);
    void appendAdministrador(Administrador usuario);
    void appendCliente(Cliente usuario);



    list<Usuario>&          getUsuarios();
    list<Administrador>&    getAdministradores();
    list<Cliente>&          getClientes();
    list<VIP>&              getVIP();
    list<Vehiculo>&         getVehiculos();
    list<Reserva>&          getReservas();


    list <Cliente>::iterator buscarCliente(string id);
    list <Administrador>::iterator buscarAdministrador(string id);
    list <Vehiculo>::iterator buscarVehiculo(string matricula);


    void iniciar();
    void login();

    bool existeUsuario(string id);
    bool esCliente(string id);
    bool esAdministrador(string id);
    bool esVehiculo(string matricula);
    bool validacionId(string id);
    bool validarMatricula(string matricula);

    ~Plataforma(){}

private:

    list <Usuario>       _usuarios;
    list <Cliente>       _clientes;
    list <Administrador> _administradores;
    list <Vehiculo>      _vehiculos;
    list <VIP>           _VIPs;
    list <Reserva>       _reservas;
    //Usuario             *_users;
    //Vehiculo            *_vehicles;
};

#endif // PLATAFORMA_H
