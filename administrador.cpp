#include "administrador.h"
#include "vehiculo.h"
#include "plataforma.h"
//
//
//     **********    ADMINISTRADOR    *******
//
//




void        Administrador::addVehiculo()
{
    string matricula;
    unsigned int capacidad;
    do{
        cout<<"\t Nuevo Vehiculo:"<<endl
           <<"Introduzca la matricula del coche: (teclee cancelar si asi lo desea):"<<endl;
        cin>>matricula;
        __fpurge(stdin);
        if(matricula!="cancelar"&&_plataforma->esVehiculo(matricula)) cout <<endl<<"Dicho vehiculo ya existe en nuestro sistema"<<endl;
        
    }while(matricula!="cancelar"&&!_plataforma->validarMatricula(matricula)||_plataforma->esVehiculo(matricula));
    if(matricula!="cancelar")
    {
        cout <<"\tIntroduzca la capacidad del coche: ";
        cin>>capacidad;
        __fpurge(stdin);
        cout <<endl;
        Vehiculo veh1(matricula,int(capacidad),1);
        _plataforma->getVehiculos().push_back(veh1);
    }
    
}

void        Administrador::addAdministrador()
{
    string id;
    do
    {
        cout<<"\tNuevo Administrador:"<<endl
           <<"\tIntroduzca un ID para el nuevo Administrador (teclee volver si desea volver al menu)"<<endl;
        cin  >> id;
        __fpurge(stdin);
    }
    while(id!="volver" && !_plataforma->validacionId(id));
    if(id!="volver"){
        Administrador admin( id ,  this->_plataforma );
        _plataforma->getAdministradores().push_back(admin);
    }
}

void        Administrador::addCliente()
{
    string id;
    do{
        cout<<"\tNuevo Cliente:"<<endl
           <<"\tIntroduzca un ID para el nuevo Cliente (teclee volver si desea volver al menu)"<<endl;
        cin  >> id;
        __fpurge(stdin);
    }
    while(id!="volver" &&!_plataforma->validacionId(id));
    if(id!="volver"){
        Cliente client1( id , _plataforma );
        _plataforma->getClientes().push_back(client1);
    }
    
}
void        Administrador::addVIP()
{
    string id;
    do{
        cout<<"\tNuevo VIP:"<<endl
           <<"\tIntroduzca un ID para el nuevo VIP (teclee volver si desea volver al menu)"<<endl;
        cin  >> id;
        __fpurge(stdin);
    }
    while(id!="volver"&&_plataforma->validacionId(id)!=1);
    if(id!="volver"){
        VIP VIP1( id ,  _plataforma );
        _plataforma->getVIP().push_back(VIP1);
    }

}

void        Administrador::modVehiculo()
{
    string matricula;
    do
    {
        cout<< "Introduzca la matricula del vehiculo que desea modificar (teclee volver si desea volver al menu) "<<endl ;
        cin >> matricula;
        __fpurge(stdin);
    }
    while(matricula!="volver"&&!_plataforma->esVehiculo(matricula));
    if(matricula!="volver")
    {
        list <Vehiculo>::iterator it = _plataforma->buscarVehiculo(matricula);
        char opcion;
        do{
            cout<< "Introduzca el parámetro que desea modificar:"<<endl
                << "\tA.\tMatricula"<<endl
                << "\tB.\tCapacidad"<<endl
                << "\tC.\tVolver"<<endl;
            cin>> opcion;
            __fpurge(stdin);
        }
        while((opcion<'A'||opcion>'C') && (opcion<'a'||opcion>'c'));
        switch (opcion) {
        case 'A': case 'a':
        {
            do
            {
                cout<<"Introduzca la nueva matricula: ";
                cin>>matricula;
                __fpurge(stdin);
            }
            while(!_plataforma->validarMatricula(matricula) && _plataforma->esVehiculo(matricula));
            string matriculaAntigua=it->getMatricula();
            it->setMatricula(matricula); // hacer un set de la matricula
            for(list <Reserva>::iterator it = _plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
            {
                if(matriculaAntigua == it->getMatricula()) it->setMatricula(matricula);
            }


            break;
        }
        case 'B': case 'b':
        {
            unsigned int capacidad; // unsigned para prevenir que se introduzca una capacidad negativa
            cout<<"Introduzca la nueva capacidad del vehiculo: ";
            cin >> capacidad;
            __fpurge(stdin);
            it->setCapacidad(int(capacidad)); //hacer un set de la capacidad
            break;
        }
        default:
            break;
        }
        cout <<endl;
    }
}

void        Administrador::modUsuario()
{
    string id;
    do{
        cout << "Introduzca el id del usuario que desea modificar: (teclee volver si desea volver al menu";
        cin >> id;
        __fpurge(stdin);
        
    } while(id!="volver"&&(!_plataforma->validacionId(id)||!_plataforma->existeUsuario(id)));
    string idn;
    do{
        cout << "Introduzca el nuevo id (teclee cancelar si asi lo quiere):";
        cin>>idn;
        __fpurge(stdin);
        if(_plataforma->existeUsuario(idn)) cerr << "Ya existe un usuario con dicho id"<<endl;
    }while(idn!="cancelar"&&_plataforma->existeUsuario(idn));
    if(idn!="cancelar")
    {
        if(_plataforma->esAdministrador(id))
        {_plataforma->buscarAdministrador(id)->setID(idn);
            cout<< endl << id <<" ahora identifica como " << idn <<endl;
        }
        else if(_plataforma->esCliente(id))
        {_plataforma->buscarCliente(id)->setID(idn);
            cout<< endl << id <<" ahora identifica como " << idn <<endl;
        }
        else if(_plataforma->esVIP(id))
        {_plataforma->buscarVIP(id)->setID(idn);
            cout<< endl << id <<" ahora identifica como " << idn <<endl;
        }
        else cout << "Id no disponible. " <<endl;
    }
}

void        Administrador::rmVehiculo()
{
    string matricula;
    do{
        
        cout << "Introduzca la matrícula del vehiculo que desea eliminar (teclee cancelar si quiere):";
        cin >> matricula;
        __fpurge(stdin);
    }
    while(matricula!="cancelar"&&(!_plataforma->validarMatricula(matricula) || !_plataforma->esVehiculo(matricula)));
    if(matricula!="cancelar") _plataforma->getVehiculos().erase(_plataforma->buscarVehiculo(matricula));
    
}

void        Administrador::rmUsuario()
{
    string id;
    do{
        
        cout << "Introduzca id del el usuario desea eliminar (teclee cancelar si quiere): ";
        cin >> id;
        __fpurge(stdin);
    }
    while(id!="cancelar"&&!_plataforma->validacionId(id));
    if(id!="cancelar")
    {
        if(_plataforma->esAdministrador(id)) _plataforma->getAdministradores().erase(_plataforma->buscarAdministrador(id));
        else if(_plataforma->esCliente(id)) _plataforma->getClientes().erase(_plataforma->buscarCliente(id));
        else cout << "No existe un usuario con id " <<id<<endl;
    }
}



void Administrador::menu()
{
    char opcion;
    do{
        do{
            
            cout<<"\tBienvenido "<< getID()<< ", has entrado como administrador"<<endl<<endl
               <<"\tElige una opcion:"<<endl<<endl
              <<"\tA.\tAdministrar vehiculos"<<endl
             <<"\tB.\tAdministrar usuarios"<<endl
            <<"\tC.\tHistorico"<<endl
            <<"\tD.\tRevisar Vehiculos"<<endl
            <<"\tE.\tSalir"<<endl<<"\t";
            cin >>opcion;
            __fpurge(stdin);
        }while((opcion<'A'||opcion>'F') && (opcion<'a'||opcion>'f'));
        
        switch (opcion)
        {
        case 'A': case 'a':
        {
            submenuVehiculo();
            break;
        }
        case 'B': case 'b':
        {
            submenuUsuario();
            break;
        }
        case 'C': case 'c':
        {
            submenuHistorico();
            break;
        }
        case 'D': case 'd':
        {
            revisarVehiculos();
            break;
        }

        default: break;
        } //switch
    }
    while(opcion!='E' && opcion!= 'e');
}
void Administrador::submenuVehiculo()
{
    char opcion;
    do{
        cout<<"\tA.\tAdd Vehiculo"<<endl
           <<"\tB.\tQuitar Vehiculo"<<endl
          <<"\tC.\tModificar Vehiculo"<<endl
         <<"\tD.\tVolver"<<endl<<endl;
        cin>>opcion;
        __fpurge(stdin);
    }while((opcion<'A'||opcion>'D')&&(opcion<'a'||opcion>'d'));
    switch(opcion)
    {
    case 'A': case 'a': {     addVehiculo();      break;  }
    case 'B': case 'b': {     rmVehiculo();       break;  }
    case 'C': case 'c': {     modVehiculo();      break;  }
    default: break;
    }
    
}

void Administrador::submenuUsuario()
{
    char opcion;
    do{
        cout<<"\t A.\tAniadir cliente"<<endl
           <<"\t B.\tAniadir VIP"<<endl
          <<"\t C.\tAniadir administrador"<<endl
         <<"\t D.\tQuitar usuario"<<endl
        <<"\t E.\tModificar usuario"<<endl
        <<"\tF.\tVolver"<<endl<<endl;
        cin>>opcion;
        __fpurge(stdin);
    }while((opcion<'A'||opcion>'F')&&(opcion<'a'||opcion>'f'));
    
    switch(opcion)
    {
    case 'A': case 'a': {     addCliente();          break;  }
    case 'B': case 'b': {     addVIP();              break;  }
    case 'C': case 'c': {     addAdministrador();    break;  }
    case 'D': case 'd': {     rmUsuario();           break;  }
    case 'E': case 'e': {     modUsuario();          break;  }
        
    default: break;
    }
}

void Administrador::submenuHistorico()
{
    char opcion;
    do{
        cout<<"\tA.\tAcceder a historico de un vehiculo"<<endl
           <<"\tB.\tAcceder a historico de un usuario"<<endl
          <<"\tC.\tVolver"<<endl<<endl;
        cin>>opcion;
        __fpurge(stdin);
    }while((opcion<'A' || opcion>'C') && (opcion<'a' || opcion!='c') );
    
    switch(opcion)
    {
    case 'A': case 'a': {     historicoVehiculo();      break;  }
    case 'B': case 'b': {     historicoUsuario();       break;  }
    default: break;
    }
    
}

void Administrador::revisarVehiculos()
{
    
    for(list <Vehiculo>::iterator it = _plataforma->getVehiculos().begin();it!=_plataforma->getVehiculos().end();it++)
    {
        if(it==_plataforma->getVehiculos().begin())  cout << "| Matricula\t|    Plazas\t|   Disponible\t|      Latitud\t|      Longitud"<<endl;
        cout<< "| "<<it->getMatricula()<<"\t|\t"<<it->getCapacidad()<<"\t|\t"<<it->getDisponible()<<"\t|\t"<<it->getLocalizacion()[0]<<"\t|\t"<<it->getLocalizacion()[1]<<endl;
    }
}

void Administrador::historicoVehiculo()
{
    string matricula;
    do{
        cout << "Introduce la matrícula del vehículo: (teclee volver para volver al menu)"<<endl;
        cin >> matricula;
        __fpurge(stdin);
    }while (matricula!="volver" && !_plataforma->esVehiculo(matricula) );
    if(matricula!="volver")
    {
        for(list <Reserva>::iterator it =_plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
        {
            if(matricula == it->getMatricula())
            {
                cout<<"Matricula: "<<it->getMatricula()<<endl
                   <<"Usuario: "<<it->getId()<<endl
                  <<"Inicio: "<< it->getInicio().toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy").toStdString()<<endl
                 <<"Fin: "<< it->getFin().toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy").toStdString()<<endl<<endl<<endl;
            }
        }
    }
}


void Administrador::historicoUsuario()
{
    string id;
    do{
        cout << "Introduce el id del usuario: (teclee volver para volver al menu)"<<endl;
        cin >> id;
        __fpurge(stdin);
        cout <<endl;
    }while (id!="volver" && !_plataforma->existeUsuario(id) );
    if(id!="volver")
    {
        for(list <Reserva>::iterator it =_plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
        {
            if(id == it->getId())
            {
                cout<<"Usuario: "<<it->getId()<<endl
                   <<"Matricula: "<<it->getMatricula()<<endl
                  <<"Inicio: "<< it->getInicio().toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy").toStdString()<<endl
                 <<"Fin: "<< it->getFin().toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy").toStdString()<<endl<<endl<<endl;
            }
        }
    }
}

