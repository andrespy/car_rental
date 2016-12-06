#include "plataforma.h"
#include "vehiculo.h"



void Plataforma::iniciar()
{

    pullDatabase();

    //double loc[2]={45.3659,65.9896};

    /*Cliente veh("1111AAA",this,loc);
    loc[2]=89.4532;
    loc[1]=152.236;
    _clientes.push_back(veh);
    Cliente veh1("2222BBB",this,loc);
    loc[2]=52.4656;
    loc[1]=12.236;
    _clientes.push_back(veh1);
    Cliente veh2("5555EEE",this,loc);
    loc[2]=91.4532;
    loc[1]=2.236;
    _clientes.push_back(veh2);
    Cliente veh3("6666FFF",this,loc);
    loc[2]=9.4532;
    loc[1]=152.236;
    _clientes.push_back(veh3);
    Cliente veh4("7777GGG",this,loc);
    loc[2]=8.4532;
    loc[1]=15.236;
    _clientes.push_back(veh4);
    Cliente veh5("8888HHH",this,loc);
    loc[2]=88.4532;
    loc[1]=15.236;
    _clientes.push_back(veh5);
    Cliente veh6("9999III",this,loc);
    loc[2]=48.4532;
    loc[1]=15.236;
    _clientes.push_back(veh6);
    Cliente veh7("0000JJJ",this,loc);
    loc[2]=8.4532;
    loc[1]=175.236;
    //_clientes.push_back(veh7);
    VIP veh8("3333CCC",this,loc);
    loc[2]=8.4532;
    loc[1]=115.236;
    _VIPs.push_back(veh8);
    VIP veh9("4444DDD",this,loc);
    loc[2]=85.4532;
    loc[1]=15.236;
    _VIPs.push_back(veh9);*/


    /*double loc[2]={45.3659,65.9896};
    Vehiculo veh("1000ABC",loc,5,1);
    loc[2]=89.4532;
    loc[1]=152.236;
    _vehiculos.push_back(veh);
    Vehiculo veh1("2000DEF",loc,8,1);
    loc[2]=52.4656;
    loc[1]=12.236;
    _vehiculos.push_back(veh1);
    Vehiculo veh2("3000GHI",loc,5,1);
    loc[2]=91.4532;
    loc[1]=2.236;
    _vehiculos.push_back(veh2);
    Vehiculo veh3("4000JKL",loc,4,1);
    loc[2]=9.4532;
    loc[1]=152.236;
    _vehiculos.push_back(veh3);
    Vehiculo veh4("5000MNO",loc,3,1);
    loc[2]=8.4532;
    loc[1]=15.236;
    _vehiculos.push_back(veh4);
    Vehiculo veh5("6000PQR",loc,3,1);
    loc[2]=88.4532;
    loc[1]=15.236;
    _vehiculos.push_back(veh5);
    Vehiculo veh6("7000STU",loc,3,1);
    loc[2]=48.4532;
    loc[1]=15.236;
    _vehiculos.push_back(veh6);
    Vehiculo veh7("8000VWX",loc,3,1);
    loc[2]=8.4532;
    loc[1]=175.236;
    _vehiculos.push_back(veh7);
    Vehiculo veh8("9000XZA",loc,3,1);
    loc[2]=8.4532;
    loc[1]=115.236;
    _vehiculos.push_back(veh8);
    Vehiculo veh9("1100BCD",loc,3,1);
    loc[2]=85.4532;
    loc[1]=15.236;
    _vehiculos.push_back(veh9);*/




    actualizarReservas();
    while(login()){actualizarReservas();}

    pushDatabase();

    list <Vehiculo>::iterator itV;
    for(itV=_vehiculos.begin();itV!=_vehiculos.end();itV++)
    {
        cout <<"\tVehiculo " << itV->getMatricula() << " con capacidad para "<< itV->getCapacidad()<< " personas."<<endl;
    }
    cout<<endl;

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



    cout << "\tEl numero de clientes es: "              << _clientes.size()        << endl
         << "\tEl numero de administradores es: "       << _administradores.size() <<endl
         << "\tY el de Vehiculos es "                   << _vehiculos.size()       << endl << endl;




}





void Plataforma::pushDatabase()
{





    //******************************************************************



    //                      PUSH ADMINISTRADORES



    //******************************************************************
    ofstream administradores;

    administradores.open("../database/administradores.dat", ios::trunc);

    if(administradores.is_open())
    {
        for(list <Administrador>::iterator it = _administradores.begin();it!=_administradores.end();it++)
        {
            administradores  <<  it->getID() <<endl;

        }

        administradores.close();
    }

    //********************************************************************************************



    //                            PUSH CLIENTES



    //**********************************************************************************************
    ofstream clientes;

    clientes.open("../database/clientes.dat", ios::trunc /*| ios::binary*/);

    if(clientes.is_open())
    {
        for(list <Cliente>::iterator it = _clientes.begin();it!=_clientes.end();it++)
        {
            clientes  <<  it->getID()<<' '<<it->getLocalizacion()[0]<<' '<<it->getLocalizacion()[1] <<endl;

        }

        clientes.close();
    }

    //********************************************************************************************



    //                            PUSH VIPS



    //**********************************************************************************************
    ofstream vips;

    vips.open("../database/vips.dat", ios::trunc /*| ios::binary*/);

    if(vips.is_open())
    {
        for(list <VIP>::iterator it = _VIPs.begin();it!=_VIPs.end();it++)
        {
            vips  <<  it->getID()<<' '<<it->getLocalizacion()[0]<<' '<<it->getLocalizacion()[1] <<endl;

        }

        vips.close();
    }












    //************************************************************************************




    //                                  PUSH VEHICULOS





    //*************************************************************************************
    ofstream vehiculos;

    vehiculos.open("../database/vehiculos.dat", ios::trunc);

    if(vehiculos.is_open())
    {
        for(list <Vehiculo>::iterator it = _vehiculos.begin();it!=_vehiculos.end();it++)
        {
            vehiculos  <<  it->getMatricula()<<' '<<  it->getCapacidad()<<' '<<it->getLocalizacion()[0]<<' '<<it->getLocalizacion()[1]<<' '<<it->getDisponible() <<endl;

        }

        vehiculos.close();
    }

    //  *****************************************************************************


    //              PUSH RESERVAS

    // ***************************************************************************

    ofstream reservas;

    reservas.open("../database/reservas.dat", ios::trunc);

    if(reservas.is_open())
    {
        for(list <Reserva>::iterator it = _reservas.begin();it!=_reservas.end();it++)
        {
            reservas  <<  it->getId()
                       <<' '<<  it->getMatricula()
                      <<' '<<it->getInicio().date().year()
                     <<' '<<it->getInicio().date().month()
                    <<' '<<it->getInicio().date().day()
                   <<' '<<it->getInicio().time().hour()
                  <<' '<<it->getInicio().time().minute()
                 <<' '<<it->getInicio().time().second()
                <<' '<<it->getFin().date().year()
               <<' '<<it->getFin().date().month()
              <<' '<<it->getFin().date().day()
             <<' '<<it->getFin().time().hour()
            <<' '<<it->getFin().time().minute()
            <<' '<<it->getFin().time().second()
            <<endl;

        }

        vehiculos.close();
    }
}



void Plataforma::pullDatabase()
{
    ifstream administradores;
    administradores.open("../database/administradores.dat",ios::in |ios::binary);
    Administrador admin(this);
    string id;
    if(administradores.is_open())
    {
        while(administradores>>id)
        {
            admin.setID(id);
            _administradores.push_back(admin);
        }
        administradores.close();
    }
    else cerr <<"No se pudo abrir ../database/administradores.dat"<<endl;



    ifstream clientes;
    clientes.open("../database/clientes.dat",ios::in |ios::binary);
    Cliente client(this);

    double loc[2];
    if(clientes.is_open())
    {
        while(clientes>>id>>loc[0]>>loc[1])
        {
            client.setID(id);
            client.setLocalizacion(loc);
            _clientes.push_back(client);
        }
        clientes.close();
    }
    else cerr <<"No se pudo abrir ../database/clientes.dat"<<endl;


    ifstream vips;
    vips.open("../database/vips.dat",ios::in |ios::binary);
    VIP vip(this);


    if(vips.is_open())
    {
        while(vips>>id>>loc[0]>>loc[1])
        {
            vip.setID(id);
            vip.setLocalizacion(loc);
            _VIPs.push_back(vip);
        }
        vips.close();
    }
    else cerr <<"No se pudo abrir ../database/vips.dat"<<endl;







    ifstream vehiculos;
    vehiculos.open("../database/vehiculos.dat",ios::in |ios::binary);
    Vehiculo veh;
    int capacidad;
    bool disponible;

    if(vehiculos.is_open())
    {
        while(vehiculos>>id>>capacidad>>loc[0]>>loc[1]>>disponible)
        {
            veh.setMatricula(id);
            veh.setLocalizacion(loc);
            veh.setCapacidad(capacidad);
            veh.setDisponible(disponible);
            _vehiculos.push_back(veh);
        }
        vehiculos.close();
    }
    else cerr <<"No se pudo abrir ../database/vehiculos.dat"<<endl;






    ifstream reservas;
    reservas.open("../database/reservas.dat",ios::in |ios::binary);
    QDateTime inicio;
    QDateTime fin;
    string matricula;
    Reserva reserva;
    int inic[6];
    int final[6];
    if(reservas.is_open())
    {
        while(reservas>>id>>matricula>>inic[5]>>inic[4]>>inic[3]>>inic[2]>>inic[1]>>inic[0]>>final[5]
              >>final[4]>>final[3]>>final[2]>>final[1]>>final[0])
        {
            inicio = QDateTime(QDate(inic[5],inic[4],inic[3]),QTime(inic[2],inic[1],inic[0]));
            fin = QDateTime(QDate(final[5],final[4],final[3]),QTime(final[2],final[1],final[0]));
            reserva.setFin(fin);
            reserva.setInicio(inicio);
            reserva.setId(id);
            reserva.setMatricula(matricula);
            _reservas.push_back(reserva);



        }
        reservas.close();
    }
    else cerr <<"No se pudo abrir ../database/reservas.dat"<<endl;



}


Plataforma::Plataforma()
{

}




list <Cliente>::iterator Plataforma::buscarCliente(string id)
{

    for(list <Cliente>::iterator it=_clientes.begin();it!=_clientes.end();it++)
    {
        if(it->getID() == id) return it;

    }

}
list <VIP>::iterator Plataforma::buscarVIP(string id)
{

    for(list <VIP>::iterator it=_VIPs.begin();it!=_VIPs.end();it++)
    {
        if(it->getID() == id) return it;

    }

}


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

void Plataforma::actualizarReservas()
{
    for(list <Reserva>::iterator it = _reservas.begin();it!=_reservas.end();it++)
    {
        if(it->getFin()<QDateTime::currentDateTime()||it->getInicio()>QDateTime::currentDateTime())   buscarVehiculo(it->getMatricula())->setDisponible(1);
    }
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



bool Plataforma::login()
{
    string id;

    do{
        cout<<"Por favor introduzca su ID de usuario para acceder al sistema"<<endl
           << "\t(si desea terminar el programa teclee salir)"<<endl<<endl
           <<"ID: ";
        cin>>id;
        //id="salir";
        if(id == "salir") return 0;

    }while(validacionId(id)==0 || existeUsuario(id)==0);
    if(esCliente(id)) buscarCliente(id)->menuCliente();
    else if(esVIP(id)) buscarVIP(id)->menuCliente();
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
