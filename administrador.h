#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "usuario.h"
#include "cliente.h"
//#include <algorithm>
//
//
//     **********    ADMINISTRADOR    *******
//
//

class Administrador : public Usuario
{

public:


    Administrador();
    Administrador(string id);
    Administrador(string id, Plataforma *plataforma):Usuario(id, plataforma){}


    //          BUSCAR
    bool existeUsuario(string id);
    bool existeVehiculo(string matricula);



    //          ADD

    void addVehiculo();
    void addUsuario();
    void addCliente();
    void addAdministrador();

    //          MODIFY

    void modVehiculo();
    void modUsuario();

    //          REMOVE

    void rmVehiculo();
    void rmUsuario();



    Vehiculo * list_vehiculos();

    //          MENUS

    void menu();
    void submenuVehiculo();
    void submenuUsuario();
    void submenuHistorico();


    void revisarVehiculos();

    //Reserva * historico(const Vehiculo & vehiculo);
    //Reserva * historico(const Usuario &user);
    // listar vehiculos por tiempo de uso


    ~Administrador(){}
};


#endif // ADMINISTRADOR_H
