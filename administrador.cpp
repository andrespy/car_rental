#include "administrador.h"
#include "vehiculo.h"
#include "plataforma.h"
//
//
//     **********    ADMINISTRADOR    *******
//
//


/*Administrador::Administrador()
{
    Usuario();
}*/


/*bool Administrador::existeVehiculo()
{

}
*/





void        Administrador::addVehiculo()        //correcto
{
    string matricula;
    unsigned int capacidad;
    do{
        cout<<"\t Nuevo Vehiculo:"<<endl
           <<"\tIntroduzca la matricula del coche "<<endl<<endl;
        cin>>matricula;

    }while(!_plataforma->validarMatricula(matricula));
    cout <<"\tIntroduzca la capacidad del coche ";
    cin>>capacidad;
    cout <<endl;
    Vehiculo veh1(matricula,int(capacidad),1);
    this->_plataforma->append(veh1);

}

/*void        Administrador::addUsuario()
{
    string id;
    cout<<"\tNuevo Usuario:"<<endl
       <<"\tIntroduzca un ID para el nuevo Usuario"<<endl;
    cin  >> id;

    Usuario usuario1( id ,  this->_plataforma );
    this->_plataforma->append(usuario1);

}*/

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
        int capacidad;
        cout<<"Introduzca la nueva capacidad del vehiculo: ";
        cin >> capacidad;
        //_plataforma->getVehiculos()->setCa //hacer un set de la capacidad
        break;
    }
    default:
        break;
    }
    cout <<endl;
}

void        Administrador::modUsuario()
{

}

void        Administrador::rmVehiculo()
{

}

void        Administrador::rmUsuario()
{

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
            <<"\tD.\tRevisar Vehiculo"<<endl
            <<"\tE.\tSalir"<<endl<<endl
            <<"\tF.\tExiste usuario."<<endl;

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
            /*case 'D': case 'd':
           {
               return 'i';
           }*/
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
               <<"\t B.\tQuitar cliente"<<endl
              <<"\t C.\tModificar cliente"<<endl<<endl

             <<"\t D.\tAniadir administrador"<<endl
            <<"\t E.\tQuitar administrador"<<endl
           <<"\t F.\tModificar administrador"<<endl<<endl;
        cin>>opcion;
    }while((opcion<'A'||opcion>'F')&&(opcion<'a'||opcion>'f'));

    switch(opcion)
    {
    /*case 'A': case 'a': {     addUsuario();          break;  }
    case 'B': case 'b': {     rmUsuario();           break;  }
    case 'C': case 'c': {     modUsuario();          break;  }*/
    case 'A': case 'a': {     addCliente();          break;  }
    case 'B': case 'b': {   /*rmCliente();*/         break;  }
    case 'C': case 'c': {     /*modCliente();*/      break;  }
    case 'D': case 'd': {     addAdministrador();    break;  }
    case 'E': case 'e': {   /*rmAdministrador();*/   break;  }
    case 'F': case 'f': {   /*modAdministrador();*/  break;  }
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



/*Reserva * Administrador::historico(const Vehiculo &vehiculo)
       {

       }

       Reserva * Administrador::historico(const Usuario &user)
       {

       }
       */
