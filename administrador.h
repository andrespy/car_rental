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





    //          MENUS

    void menu();
    void submenuVehiculo();
    void submenuUsuario();
    void submenuHistorico();

    //      HISTORIALES

    void revisarVehiculos();
    void historicoVehiculo();
    void historicoUsuario();



    ~Administrador(){}
};


#endif // ADMINISTRADOR_H
