#include "cliente.h"
#include "vehiculo.h"
#include "reserva.h"
#include <stdlib.h>
//
//
//     **********    CLIENTE    *******
//
//
double * Cliente::getLocalizacion()
{
    return _localizacion;
}
Cliente::Cliente(string id, Plataforma *plataforma, double localizacion[]): Usuario(id,plataforma)
{

    _localizacion[1] = localizacion[1];
    _localizacion[0] = localizacion[0];
}

void Cliente::setLocalizacion(double localizacion[])
{
    _localizacion[1] = localizacion[1];
    _localizacion[0] = localizacion[0];
}

bool Cliente::colisionReserva( Reserva  reserva)
{
    for(list <Reserva>::iterator it = _plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
    {
        if(it->getMatricula()==reserva.getMatricula() &&

                ((reserva.getInicio()<it->getInicio() && reserva.getFin()>reserva.getInicio()
                  &&(reserva.getInicio().time()<it->getInicio().time() && reserva.getFin().time()>reserva.getInicio().time()))||

                 (reserva.getInicio()<it->getFin() && reserva.getFin()>it->getFin()
                  &&(reserva.getInicio().time()<it->getFin().time() && reserva.getFin().time()>it->getFin().time()))||


                 (reserva.getInicio()<it->getInicio()&&reserva.getFin()>it->getFin()
                  &&(reserva.getInicio().time()<it->getInicio().time()&&reserva.getFin().time()>it->getFin().time()))||

                 (reserva.getInicio()>it->getInicio()&&reserva.getFin()<it->getFin())
                 &&(reserva.getInicio().time()>it->getInicio().time()&&reserva.getFin().time()<it->getFin().time())))





        {

            return 1;

        }
    }
    return 0;
}



 void Cliente::reservar()
{
    string matricula;

    do
    {
        cout << "Introduce la matrIcula del coche que desea reservar: ";
        cin >> matricula;
        __fpurge(stdin);

        cout<<endl;
        if(!_plataforma->esVehiculo(matricula)) cout << "No existe dicho vehiculo."<<endl;
        /*else if(!_plataforma->buscarVehiculo(matricula)->getDisponible())
                cout<<"Dicho vehiculo no esta disponible en estos momentos."<<endl;*/

    }
    while(!_plataforma->esVehiculo(matricula));

    Reserva reserva(_id,matricula);

    do{

        reserva.pideFecha();
    if(colisionReserva(reserva)) cerr << "Error de colision de reservas"<<endl;
    }while (colisionReserva(reserva));
    _plataforma->getReservas().push_back(reserva);
    _plataforma->actualizarReservas();
    cout<<"¡Enhorabuena! Ha reservado el vehiculo "
       <<reserva.getMatricula()
      <<endl;


}
void Cliente::dondeAparque()
{
    bool sinreservas =1;
    char opcion = 'o';
    for(list <Reserva>::iterator it = _plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
    {
        if(it->getId()==_id && it->getFin()>QDateTime::currentDateTime()&&it->getInicio()<QDateTime::currentDateTime())
        {
            sinreservas =0;
            cout<<endl<<"Su vehiculo con matricula: "<<it->getMatricula()<<" se encuentra localizado en "
               <<_plataforma->buscarVehiculo(it->getMatricula())->getLocalizacion()[1]<< " "<<
                 _plataforma->buscarVehiculo(it->getMatricula())->getLocalizacion()[0]<<endl;
        }
    }

    if(sinreservas){cout<<endl<<"Actualmente no tiene ningun vehiculo alquilado."<<endl;}
    else{
        cout<<endl<<"¿Desea iniciar la navegacion hasta el con Google Maps?(si es si pulse S si no cualquier otra tecla) "
           <<endl;
        cin >>opcion;
        __fpurge(stdin);
        if(opcion == 'S'){cout<<"No tiene la aplicacion Google Maps instalada"<<endl;}
    }
}

void Cliente::historial()
{
    bool sinreservas =1;

    for(list <Reserva>::iterator it =_plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
    {
        if(it->getId()==_id)
        {
            if(sinreservas){cout << "Sus reservas hasta la fecha son: "<<endl<<endl;sinreservas = 0;}
            cout <<"Vehiculo con matricula "<< it->getMatricula()<<endl
                <<"Inicio de reserva "
               <<it->getInicio().toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy").toStdString();

            if(it->getFin()<QDateTime::currentDateTime())
            {cout <<endl<<" Dicha reserva finalizo el dia ";}

            else cout<<endl <<" Dicha reserva finaliza el dia ";

            cout<<it->getFin().toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy").toStdString()<<endl<<endl;

        }

    }
    if(sinreservas) cout << endl << "No nos consta que haya reservado ningún vehiculo hasta la fecha"<<endl<<endl;

}

void        Cliente::menuCliente()
{
    char opcion;
    do{
        do{

            cout<<"\tBienvenido "<<_id<<endl
               <<"\tElige una de las opciones"<<endl<<endl
              <<"\tA. Ver la localización de los vehículos."<<endl
             <<"\tB. Obtener el coche más cercano"<<endl
            <<"\tC. Realizar una petición de reserva"<<endl
            <<"\tD. Acceder a su propio historial"<<endl
            <<"\tE. ¿Donde aparque mi coche?"<<endl
            <<"\tF. Salir"<<endl <<endl;

            cin>>opcion;
            __fpurge(stdin);
            switch (opcion) {
            case 'A':case 'a':
            {
                displayVehiculos();
                break;
            case 'B':case 'b':
                {
                    displayVehiculoCercano();
                    break;
                }
                case 'C':case 'c':
                {
                    reservar();
                    break;
                }
                case 'D':case'd':
                {
                    historial();
                    break;
                }
                case 'E':case'e':
                {
                    dondeAparque();
                    break;
                }
                default:
                    break;
                }
            }
            cout << endl;


        }while((opcion<'A'||opcion>'F') && (opcion<'a'||opcion>'f'));
    }

    while(opcion!='F'&&opcion!='f');


}

void Cliente::displayVehiculos()
{
    bool i=1;
    cout<<endl<<"Por motivos de seguridad no se mostrara la localizacion de los vehiculos que esten"<<
          " reservados en estos momentos. Sin embargo, puede ver sus matriculas por si quiere"<<
          " reservarlo para otro momento"<<endl;
    for(list<Vehiculo>::iterator it = _plataforma->getVehiculos().begin(); it!= _plataforma->getVehiculos().end();it++)
    {


        if(it==_plataforma->getVehiculos().begin()){  cout << "| Matricula\t| Latitud\t| Longitud"<<endl; i=0;}
        if( it->getDisponible())cout<< "| "<<it->getMatricula()<<"\t| "<<it->getLocalizacion()[0]<<"\t| "<<it->getLocalizacion()[1]<<endl;
        else cout<< "| "<<it->getMatricula()<<"\t| "<<"------"<<"\t| "<<"------"<<endl;

    }
    if (i) cout<< "No disponemos de vehiculos en este momento"<<endl;

}






void Cliente::displayVehiculoCercano()
{
    if(_plataforma->getVehiculos().begin()!=_plataforma->getVehiculos().end())
    {
        float l=999999;
        list<Vehiculo>::iterator itCercano;
        for(list<Vehiculo>::iterator it = _plataforma->getVehiculos().begin(); it!= _plataforma->getVehiculos().end();it++)
        {
            if( it->getDisponible() && distanciaAVehiculo(it->getLocalizacion())<l)
            {
                itCercano = it;
                l = distanciaAVehiculo(it->getLocalizacion());
            }
        }

        if(l!=999999) cout << "El vehiculo más cercano a su posicion es " << itCercano->getMatricula()<<
                              " a "<< distanciaAVehiculo(itCercano->getLocalizacion())*111.319<<"KM"<<endl;
        else cout << "No disponemos de vehiculos libres"<< endl;
    }
    else cout << "No disponemos de vehiculos libres"<< endl;
}




double Cliente::distanciaAVehiculo(double * localizacion)
{
    return sqrt(pow((_localizacion[1]-localizacion[1]),2)+pow((_localizacion[0]-localizacion[0]),2));

}

