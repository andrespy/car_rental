#include "administrador.h"
#include "vehiculo.h"
#include "plataforma.h"
//
//
//     **********    ADMINISTRADOR    *******
//
//




void        Administrador::addVehiculo()        //correcto
{
    string matricula;
    unsigned int capacidad;
    do{
        cout<<"\t Nuevo Vehiculo:"<<endl
           <<"\tIntroduzca la matricula del coche: ";
        cin>>matricula;

    }while(!_plataforma->validarMatricula(matricula));
    cout <<"\tIntroduzca la capacidad del coche: ";
    cin>>capacidad;
    cout <<endl;
    Vehiculo veh1(matricula,int(capacidad),1);
    this->_plataforma->append(veh1);

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
    this->_plataforma->appendAdministrador(admin);

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
    Cliente client1( id ,  this->_plataforma );
    this->_plataforma->appendCliente(client1);

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
        if(_plataforma->esAdministrador(idn)    ||  _plataforma->esCliente(idn)) cerr << "Ya existe un usuario con dicho id"<<endl;
    }while(_plataforma->esAdministrador(idn)    ||  _plataforma->esCliente(idn) ||  !_plataforma->validacionId(idn));

    if(_plataforma->esAdministrador(id))
    {_plataforma->buscarAdministrador(id)->setID(idn);
        cout<< endl << id <<" ahora identifica como " << idn <<endl;
    }
    else if(_plataforma->esCliente(id))
    {_plataforma->buscarCliente(id)->setID(idn);
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
              <<"\tA.\tVehiculos"<<endl
             <<"\tB.\tUsuarios"<<endl
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
            //id="Anonmo";
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
          <<"\tC.\tModificar Vehiculo"<<endl<<endl;
        cin>>opcion;
    }while(opcion!='A'&&opcion!='B'&&opcion!='C'&&opcion!='a'&&opcion!='b'&&opcion!='c');
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
        cout/*<<"\t A.\tAniadir Usuario"<<endl
                                                           <<"\t B.\tQuitar Usuario"<<endl
                                                          <<"\t C.\tModificar Usuario"<<endl<<endl
                                                        */
                <<"\t A.\tAniadir cliente"<<endl
               <<"\t B.\tAniadir administrador"<<endl
              <<"\t C.\tQuitar usuario"<<endl
             <<"\t D.\tModificar usuario"<<endl<<endl;
        cin>>opcion;
    }while((opcion<'A'||opcion>'D')&&(opcion<'a'||opcion>'d'));

    switch(opcion)
    {
    /*case 'A': case 'a': {     addUsuario();          break;  }
    case 'B': case 'b': {     rmUsuario();           break;  }
    case 'C': case 'c': {     modUsuario();          break;  }*/
    case 'A': case 'a': {     addCliente();          break;  }
    case 'B': case 'b': {     addAdministrador();    break;  }
    case 'C': case 'c': {     rmUsuario();           break;  }
    case 'D': case 'd': {     modUsuario();          break;  }

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
    case 'A': case 'a': {     /*historicoVehiculo();*/      break;  }
    case 'B': case 'b': {     /*historicoUsuario(); */      break;  }
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

/*Reserva * Administrador::historico(const Vehiculo &vehiculo)
       {

       }

       Reserva * Administrador::historico(const Usuario &user)
       {

       }
       */
