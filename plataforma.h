#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <iostream>
#include <fstream>
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


    void pullDatabase();
    void pushDatabase();

    void setUsuario(const Usuario &usuario);
    void setVehiculo(const Vehiculo &vehiculo);








    list<Administrador>&    getAdministradores();
    list<Cliente>&          getClientes();
    list<VIP>&              getVIP();
    list<Vehiculo>&         getVehiculos();
    list<Reserva>&          getReservas();


    list <Cliente>::iterator                buscarCliente(string id);
    list <Administrador>::iterator          buscarAdministrador(string id);
    list <Vehiculo>::iterator               buscarVehiculo(string matricula);
    list <VIP>::iterator                    buscarVIP(string id);

    void iniciar();
    bool login();
    void actualizarReservas();

    bool existeUsuario(string id);

    bool esCliente(string id);
    bool esAdministrador(string id);
    bool esVIP(string id);
    bool esVehiculo(string matricula);

    bool validacionId(string id);
    bool validarMatricula(string matricula);






    ~Plataforma(){}

private:


    list <Cliente>       _clientes;
    list <Administrador> _administradores;
    list <Vehiculo>      _vehiculos;
    list <VIP>           _VIPs;
    list <Reserva>       _reservas;

};

#endif // PLATAFORMA_H
