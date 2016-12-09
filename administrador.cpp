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
           <<"\tIntroduzca la matricula del coche: ";
        cin>>matricula;
        if(_plataforma->esVehiculo(matricula)) cout <<"Dicho vehiculo ya existe en nuestro sistema"<<endl;
        
    }while(!_plataforma->validarMatricula(matricula)||_plataforma->esVehiculo(matricula));
    cout <<"\tIntroduzca la capacidad del coche: ";
    cin>>capacidad;
    cout <<endl;
    Vehiculo veh1(matricula,int(capacidad),1);
    _plataforma->getVehiculos().push_back(veh1);
    
}

void        Administrador::addAdministrador()
{
    string id;
    do
    {
        cout<<"\tNuevo Administrador:"<<endl
           <<"\tIntroduzca un ID para el nuevo Administrador"<<endl;
        cin  >> id;
    }
    while(!_plataforma->validacionId(id));
    Administrador admin( id ,  this->_plataforma );
    _plataforma->getAdministradores().push_back(admin);
    
}

void        Administrador::addCliente()
{
    string id;
    do{
        cout<<"\tNuevo Cliente:"<<endl
           <<"\tIntroduzca un ID para el nuevo Cliente"<<endl;
        cin  >> id;
    }
    while(_plataforma->validacionId(id)!=1);
    Cliente client1( id , _plataforma );
    _plataforma->getClientes().push_back(client1);
    
}
void        Administrador::addVIP()
{
    string id;
    do{
        cout<<"\tNuevo VIP:"<<endl
           <<"\tIntroduzca un ID para el nuevo VIP"<<endl;
        cin  >> id;
    }
    while(_plataforma->validacionId(id)!=1);
    VIP VIP1( id ,  _plataforma );
    _plataforma->getVIP().push_back(VIP1);

}

void        Administrador::modVehiculo()
{
    string matricula;
    do
    {
        cout<< "Introduzca la matricula del vehiculo que desea modificar: " ;
        cin >> matricula;
    }
    while(!_plataforma->esVehiculo(matricula));
    list <Vehiculo>::iterator it = _plataforma->buscarVehiculo(matricula);
    char opcion;
    do{
        cout<< "Introduzca el parámetro que desea modificar:"<<endl
            << "\tA.\tMatricula"<<endl
            << "\tB.\tCapacidad"<<endl
            << "\tC.\tVolver"<<endl;
        cin>> opcion;
    }
    while(opcion<'A'||opcion>'C' && opcion<'a'||opcion>'c');
    switch (opcion) {
    case 'A': case 'a':
    {
        do
        {
            cout<<"Introduzca la nueva matricula: ";
            cin>>matricula;
        }
        while(_plataforma->validarMatricula(matricula)&& _plataforma->esVehiculo(matricula));
        it->setMatricula(matricula); // hacer un set de la matricula
        break;
    }
    case 'B': case 'b':
    {
        unsigned int capacidad; // unsigned para prevenir que se introduzca una capacidad negativa
        cout<<"Introduzca la nueva capacidad del vehiculo: ";
        cin >> capacidad;
        it->setCapacidad(int(capacidad)); //hacer un set de la capacidad
        break;
    }
    default:
        break;
    }
    cout <<endl;
}

void        Administrador::modUsuario()
{
    string id;
    do{
        cout << "Introduzca el id del usuario que desea modificar: ";
        cin >> id;
        
    } while(!_plataforma->validacionId(id));
    string idn;
    do{
        cout << "Introduzca el nuevo id: ";
        cin>>idn;
        if(_plataforma->esAdministrador(idn)    ||  _plataforma->esCliente(idn) || _plataforma->esVIP(idn)) cerr << "Ya existe un usuario con dicho id"<<endl;
    }while(_plataforma->esAdministrador(idn)    ||  _plataforma->esCliente(idn) ||  !_plataforma->validacionId(idn));
    
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

void        Administrador::rmVehiculo()
{
    string matricula;
    do{
        
        cout << "Introduzca la matrícula del vehiculo que desea eliminar: ";
        cin >> matricula;
    }
    while(!_plataforma->validarMatricula(matricula) || !_plataforma->esVehiculo(matricula));
    _plataforma->getVehiculos().erase(_plataforma->buscarVehiculo(matricula));
    
}

void        Administrador::rmUsuario()
{
    string id;
    do{
        
        cout << "Introduczca id del el usuario desea eliminar: ";
        cin >> id;
    }
    while(!_plataforma->validacionId(id));
    
    if(_plataforma->esAdministrador(id)) _plataforma->getAdministradores().erase(_plataforma->buscarAdministrador(id));
    else if(_plataforma->esCliente(id)) _plataforma->getClientes().erase(_plataforma->buscarCliente(id));
    else cout << "No existe un usuario con id " <<id<<endl;
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
            
            cin>>opcion;
            //opcion='F';
        }while(opcion<'A'||opcion>'F' && opcion<'a'||opcion>'f');
        
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
        case 'F': case 'f':
        {
            cout<<"introduce ID"<< endl;
            string id;
            cin >> id;
            if(_plataforma->existeUsuario(id)==1) cout << "existe"<<endl;
            else cout << "No existe"<<endl;
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
           <<"\tB.\tAcceder a historico de un usuario"<<endl<<endl;
        cin>>opcion;
    }while(opcion!='A' && opcion!='B' && opcion!='a' && opcion!='b' );
    
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
    }while (matricula!="volver" && !_plataforma->esVehiculo(matricula) );
    if(matricula!="volver")
    {
        for(list <Reserva>::iterator it =_plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
        {
            if(matricula == it->getMatricula())
            {
                cout<<"Matricula: "<<it->getMatricula()<<endl
                   <<"Usuario: "<<it->getId()<<endl
                  <<"Inicio: "<< it->getInicio().date().day()<<"/"
                 <<it->getInicio().date().month()<<"/"<<it->getInicio().date().year()
                << " a las " <<it->getInicio().time().hour()<<":"<<it->getInicio().time().minute()<<endl
                <<"Fin: "<< it->getFin().date().day()<<"/"
               <<it->getFin().date().month()<<"/"<<it->getFin().date().year()
              << " a las " <<it->getFin().time().hour()<<":"<<it->getFin().time().minute()<<endl<<endl<<endl;
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
                  <<"Inicio: "<< it->getInicio().date().day()<<"/"
                 <<it->getInicio().date().month()<<"/"<<it->getInicio().date().year()
                << " a las " <<it->getInicio().time().hour()<<":"<<it->getInicio().time().minute()<<endl
                <<"Fin: "<< it->getFin().date().day()<<"/"
               <<it->getFin().date().month()<<"/"<<it->getFin().date().year()
              << " a las " <<it->getFin().time().hour()<<":"<<it->getFin().time().minute()<<endl<<endl<<endl;
            }
        }
    }
}

