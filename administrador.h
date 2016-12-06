#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "usuario.h"
#include "cliente.h"
#include "vip.h"
//#include <algorithm>
//
//
//     **********    ADMINISTRADOR    *******
//
//

class Administrador : public Usuario
{

public:


    Administrador():Usuario(){}
    Administrador(Plataforma *plataforma):Usuario(plataforma){}
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
    void addVIP();

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




    ~Administrador(){}
};


#endif // ADMINISTRADOR_H
