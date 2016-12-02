#include "plataforma.h"
#include "vehiculo.h"
//#include "reserva.h"
//#include "usuario.h"


void Plataforma::iniciar()
{
    //  aqui habra que importar de una fuente externa los datos de otra sesion
   // pullDatabase();

    Administrador admin("0000AAA",this);
    _administradores.push_back(admin);
    Cliente client("0001AAA",this);
    _clientes.push_back(client);
    Vehiculo veh1("3233GHT",9,0);
    double loc[2] = {40.563,25.659};
    veh1.setLocalizacion(loc);
    _vehiculos.push_back(veh1);

    Vehiculo veh5("0000AAA",9,1);
    double loc2[2] = {12.563,25.659};
    veh5.setLocalizacion(loc2);
    _vehiculos.push_back(veh5);

    Vehiculo veh2("3234GUI",5,1);
    _vehiculos.push_back(veh2);
    veh2.setMatricula("0000AAA");


    while(login()){}
    //pushDatabase();







    list <Vehiculo>::iterator itV;
    for(itV=_vehiculos.begin();itV!=_vehiculos.end();itV++)
    {
        cout <<"\tVehiculo " << itV->getMatricula() << " con capacidad para "<< itV->getCapacidad()<< " personas."<<endl;
    }
    cout<<endl;
    list <Usuario>::iterator itU;
    for(itU=_usuarios.begin();itU!=_usuarios.end();itU++)
    {
        cout <<"\tUsuario " << itU->getID() << endl;

    }
    list <Cliente>::iterator itC;
    for(itC=_clientes.begin();itC!=_clientes.end();itC++)
    {
        cout <<"\tCliente " << itC->getID() << endl;

    }
    list <Administrador>::iterator itA;
    for(itA=_administradores.begin();itA!=_administradores.end();itA++)
    {
        cout <<"\tAdministrador " << itA->getID() << endl;

    }



    cout << "\tEl numero de usuarios en el sistema es " << _usuarios.size()        << endl
         << "\tEl numero de clientes es: "              << _clientes.size()        << endl
         << "\tEl numero de administradores es: "       << _administradores.size() <<endl
         << "\tY el de Vehiculos es "                   << _vehiculos.size()       << endl << endl;




}




Plataforma::Plataforma()
{

}
void Plataforma::pushDatabase()
{
    ofstream administradores;
    administradores.open("../database/administradores.bin", ios::out | ios::binary);

    if(administradores.is_open())
    {
        //administradores.write((char*)_administradores,sizeof(Administrador)*_administradores.size());

        Administrador *adminlist = new Administrador[_administradores.size()];
        int i=0;
        for(list <Administrador>::iterator it = _administradores.begin();it!=_administradores.end();it++)
        {
            adminlist[i] = *it;
            i++;
        }

        for(int i = 0 ; i<_administradores.size();i++)
        {
            administradores.write(((char*)&adminlist[i]),sizeof(Administrador));
            cout<<"ESCRITO"<<adminlist->getID()<<endl;
        }
        delete [] adminlist;


        /*for(list <Administrador>::iterator it = _administradores.begin();it!=_administradores.end();it++)
        {

            administradores << it->getID()<<endl;
        }*/
        administradores.close();
    }

    /*ofstream clientes;
    clientes.open("../database/clientes.bin", ios::out | ios::binary);
    if(clientes.is_open())
    {
        for(list <Cliente>::iterator it = _clientes.begin();it!=_clientes.end();it++)
        {
            clientes << it->getID()<<endl;
        }
        clientes.close();
    }
    ofstream vehiculos;
    vehiculos.open("../database/vehiculos.bin", ios::out | ios::binary);
    if(vehiculos.is_open())
    {
        for(list <Vehiculo>::iterator it = _vehiculos.begin();it!=_vehiculos.end();it++)
        {
            vehiculos << it->getMatricula()<<endl;
            vehiculos << it->getCapacidad()<<endl;
            //vehiculos << it->getLocalizacion()[1]<<endl;
            //vehiculos << it->getLocalizacion()[0]<<endl;
            vehiculos << it->getDisponible()<<endl;
        }
        vehiculos.close();
    }
*/
}



void Plataforma::pullDatabase()
{
    ifstream administradores;
    administradores.open("../database/administradores.bin",ios::in |ios::binary);
    if(!administradores) cerr << "Error al abrir ../database/administradores.bin"<<endl;
    else {

        Administrador *admin/* = new Administrador[5]*/;


            administradores.read(((char*)admin),sizeof(Administrador));
            _administradores.push_back(*admin);



        //delete [] adminlist;
        /*Administrador admin(this);
        string id;
        do{
            administradores >> id;
            admin.setID(id);
            _administradores.push_back(admin);
        }
        while(!administradores.eof());
        */

        administradores.close();
    }

    ifstream clientes;
    clientes.open("../database/clientes.bin",ios::in |ios::binary);
    if(!clientes) cerr << "Error al abrir ../database/clientes.bin"<<endl;
    else {
        Cliente client(this);
        string id;
        do{
            clientes >> id;
            client.setID(id);
            _clientes.push_back(client);
        }
        while(!clientes.eof());
        /* while(administradores.read((char *)(&admin), sizeof(Administrador) ));*/
        //_administradores.push_back(admin);

        clientes.close();
    }

    char buffer[100];
    ifstream vehiculos ("../database/vehiculos.bin",ios::in |ios::binary);
    if(!vehiculos) cerr << "Error al abrir ../database/vehiculos.bin"<<endl;
    else {
        Vehiculo veh;
        string matricula;
        double localizacion[2];
        bool disponible;
        int capacidad;
        do{

            vehiculos >> matricula ;
            vehiculos >> capacidad ;
            vehiculos>> localizacion[1] ;
            vehiculos>> localizacion[0];
            vehiculos>>disponible;
            veh.setMatricula(matricula);
            veh.setCapacidad(capacidad);
            veh.setDisponible(disponible);
            veh.setLocalizacion(localizacion);



            _vehiculos.push_back(veh);
        }
        while(!vehiculos.eof());

        vehiculos.close();
    }
}

list <Cliente>::iterator Plataforma::buscarCliente(string id)
{

    for(list <Cliente>::iterator it=_clientes.begin();it!=_clientes.end();it++)
    {
        if(it->getID() == id) return it;

    }
}
//bool Plataforma::validarMatricula(string matricula)
//{

//    if(matricula.length()!=7)
//    {
//        cout<<"Error de formato. Recuerda 0123ABC"<<endl;
//        return 0;
//    }
//    for(int i=0;i<4;i++)
//    {
//        if(matricula[i]<'0'||matricula[i]>'9')
//        {
//            cout<<"Error. Recuerda los primeros 4 caracteres son numeros"<<endl;
//            return 0;
//        }
//        for(int i=4;i<7;i++)
//        {
//            if(matricula[i]<'A'||matricula[i]>'Z')
//            {
//                cout<<"Error. Recuerda los ultimos 3 caracteres son letras mayusculas"<<endl;
//                return 0;
//            }
//        }

//        return 1;
//    }
//}


list <Vehiculo>::iterator Plataforma::buscarVehiculo(string matricula)
{

    for(list <Vehiculo>::iterator it=_vehiculos.begin();it!=_vehiculos.end();it++)
    {
        if(it->getMatricula() == matricula) return it;

    }

}







list <Administrador>::iterator Plataforma::buscarAdministrador(string id)
{

    for(list <Administrador>::iterator it=_administradores.begin();it!=_administradores.end();it++)
    {
        if(it->getID() == id) return it;

    }
}

/*for(list <Cliente>::iterator itC=_clientes.begin();itC!=_clientes.end();itC++)
{
    if(itC->getID()==id) return itC;

}
list <Administrador>::iterator itA;
for(itA=_administradores.begin();itA!=_administradores.end();itA++)
{
    if(itA->getID()==id) return itA;

}

}*/



void Plataforma::append(Vehiculo vehiculo)
{
    _vehiculos.push_back(vehiculo);


    /* if(_vehiculos!=NULL)
    {


        Vehiculo *tmpVehiculos = new Vehiculo[_numVehiculos];

        for(  int i = 0 ; i  < _numVehiculos ; i++)
        {
            tmpVehiculos[i] = _vehiculos[i];
        }

        delete [] _vehiculos;

        _vehiculos = new Vehiculo[_numVehiculos+1];

        for(  int i = 0 ; i  < _numVehiculos ; i++)
        {
            *(_vehiculos+i) = *(tmpVehiculos+i);
        }

        delete [] tmpVehiculos;

        _numVehiculos++;

        *(_vehiculos+_numVehiculos)=vehiculo;
    }

    else
    {
        _numVehiculos++;
        _vehiculos= new Vehiculo[_numVehiculos];
        _vehiculos = &vehiculo;

    }
    //deletear vehiculos en array antiguo
    // aumentar tamaño de vehiculos en uno
    //
*/
}




void Plataforma::appendCliente(Cliente usuario)
{
    _clientes.push_back(usuario);

    /* if(_usuarios!=NULL)
    {

        Usuario *tmpUsuarios = new Usuario[_numUsuarios];

        for(  int i = 0 ; i  < _numUsuarios ; i++)
        {
            *(tmpUsuarios+i) = _usuarios[i];
        }

        delete [] _usuarios;

        _usuarios = new Usuario[_numUsuarios+1];

        for(  int i = 0 ; i  < _numUsuarios ; i++)
        {
            _usuarios[i] = tmpUsuarios[i];
        }

        delete [] tmpUsuarios;

        _numUsuarios++;

        *(_usuarios+_numUsuarios) = usuario;
    }

    else
    {
        _numUsuarios++;
        _usuarios= new Usuario[_numUsuarios];
        *_usuarios = usuario;

    }
*/
}

void Plataforma::appendAdministrador(Administrador usuario)
{
    _administradores.push_back(usuario);
}

list <Usuario>& Plataforma::getUsuarios()
{
    return _usuarios;
}

list <Vehiculo>&   Plataforma::getVehiculos()
{
    return _vehiculos;
}
list<Administrador>& Plataforma::getAdministradores()
{
    return _administradores;
}

list<Cliente>& Plataforma::getClientes()
{
    return _clientes;
}


list<VIP>& Plataforma::getVIP()
{
    return _VIPs;
}
list<Reserva>& Plataforma::getReservas()
{
    return _reservas;
}

/*Plataforma & Plataforma::operator=(Plataforma plataforma)
{
    _usuarios        = plataforma._usuarios;
    _vehiculos       = plataforma._vehiculos;
    _numVehiculos   = plataforma._numVehiculos;
    _numUsuarios    = plataforma._numUsuarios;

    return *this;
}*/

bool Plataforma::login()
{
    string id;





    do{
        cout<<"Por favor introduzca su ID de usuario para acceder al sistema"<<endl
           << "\t(si desea terminar el programa teclee salir)"<<endl<<endl
           <<"ID: ";
        cin>>id;
        if(id == "salir") return 0;

    }while(validacionId(id)==0 || existeUsuario(id)==0);
    if(esCliente(id)) buscarCliente(id)->menuCliente();
    else if(esAdministrador(id)) buscarAdministrador(id)->menu();
    return 1;

}
bool Plataforma::esCliente(string id)
{
    for(list <Cliente>::iterator itC=_clientes.begin();itC!=_clientes.end();itC++)
    {
        if(itC->getID()==id) return 1;
    }
    return 0;
}
bool Plataforma::esVIP(string id)
{
    for(list <VIP>::iterator itC=_VIPs.begin();itC!=_VIPs.end();itC++)
    {
        if(itC->getID()==id) return 1;
    }
    return 0;
}
bool Plataforma::esAdministrador(string id)
{
    for(list <Administrador>::iterator itA=_administradores.begin();itA!=_administradores.end();itA++)
    {


        if(itA->getID()==id) return 1;

    }
    return 0;
}

bool Plataforma::existeUsuario(string id)
{

    if( !esCliente(id) && !esAdministrador(id) && !esVIP(id)  )
    {
        cout<<"No existe dicho usuario"<<endl;
        return 0;
    }
    return 1;
}
bool Plataforma::esVehiculo(string matricula)
{
    for(list <Vehiculo>::iterator it=_vehiculos.begin();it!=_vehiculos.end();it++)
    {
        if(it->getMatricula()==matricula) return 1;
    }
    cout<<"No existe dicho vehiculo"<<endl;
    return 0;

}

bool Plataforma::validacionId(string id)
{
    if(id.length()!=7)
    {
        cout<<"Error de formato. Recuerda 0000XXX"<<endl;
        return 0;
    }
    for(int i=0;i<4;i++)
    {
        if(id[i]<'0'||id[i]>'9')
        {
            cout<<"Error. Recuerda los primeros 4 caracteres son numeros"<<endl;
            return 0;
        }
    }
    for(int i=4;i<7;i++)
    {
        if(id[i]<'A'||id[i]>'Z')
        {
            cout<<"Error. Recuerda los ultimos 3 caracteres son letras mayusculas"<<endl;
            return 0;
        }
    }

    return 1;


}

bool Plataforma::validarMatricula(string matricula)
{

    if(matricula.length()!=7)
    {
        cout<<"Error de formato. Recuerda 0123ABC"<<endl;
        return 0;
    }
    for(int i=0;i<4;i++)
    {
        if(matricula[i]<'0'||matricula[i]>'9')
        {
            cout<<"Error. Recuerda los primeros 4 caracteres son numeros"<<endl;
            return 0;
        }
        for(int i=4;i<7;i++)
        {
            if(matricula[i]<'A'||matricula[i]>'Z')
            {
                cout<<"Error. Recuerda los ultimos 3 caracteres son letras mayusculas"<<endl;
                return 0;
            }
        }

        return 1;
    }
}
