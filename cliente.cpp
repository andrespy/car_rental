#include "cliente.h"
#include "vehiculo.h"
#include "reserva.h"
//
//
//     **********    CLIENTE    *******
//
//
double * Cliente::getLocalizacion()
{
    return _localizacion;
}

void Cliente::setLocalizacion(double localizacion[])
{
    _localizacion[1] = localizacion[1];
    _localizacion[0] = localizacion[0];
}





void Cliente::reservar()
{
    string matricula;
    do
    {
        do
        {
            cout << "Introduce la matrIcula del coche que desea reservar: ";
            cin >> matricula;
            cout<<endl;
            if(!_plataforma->esVehiculo(matricula)) cout << "No existe dicho vehiculo."<<endl;
            else if(!_plataforma->buscarVehiculo(matricula)->getDisponible())
                cout<<"Dicho vehiculo no esta disponible en estos momentos."<<endl;

        }
        while(!_plataforma->esVehiculo(matricula));
    }
    while(!_plataforma->buscarVehiculo(matricula)->getDisponible());

    /*int dias;


    cout << "Introduzca el numero de dias que desea que dure la reserva: ";
    cin>> dias;

    QDateTime inicio = QDateTime::currentDateTime();
    QDateTime fin= inicio.addDays(dias);
    */

    Reserva reserva(_id,_plataforma->buscarVehiculo(matricula)->getMatricula());
    reserva.pideFecha();
    _plataforma->getReservas().push_back(reserva);
    _plataforma->buscarVehiculo(matricula)->setDisponible(0);
    cout<<"¡Enhorabuena! Ha reservado el vehiculo " <<reserva.getMatricula()
       <<". Su reserva comprende hasta el día "
      <<reserva.getFin().date().day()
     <<" de "<<reserva.getFin().date().month()<< " de "
    << reserva.getFin().date().year()<< " a las "
    << reserva.getFin().time().hour()<<":"
    <<reserva.getFin().time().minute()<<endl;


}

void Cliente::historial()
{
    cout << "Sus reservas hasta la fecha son: "<<endl;
    for(list <Reserva>::iterator it =_plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
    {
        if(it->getId()==_id)
        {
            cout << "\tEl dia " <<it->getInicio().date().day()<< " del " <<it->getInicio().date().month() <<" de "<<it->getInicio().date().year() <<" reservo el vehiculo con matricula "<< it->getMatricula()<<endl;
        }
    }


}

void        Cliente::menuCliente()
{
    char opcion;
    do{
        do{

            cout<<"\tBienvenido, has entrado como cliente"<<endl
               <<"\tElige una de las opciones"<<endl<<endl
              <<"\tA. Ver la localización de los vehículos."<<endl
             <<"\tB. Obtener el coche más cercano"<<endl
            <<"\tC. Realizar una petición de reserva"<<endl
            <<"\tD. Acceder a su propio historial"<<endl
            <<"\tE. Salir"<<endl <<endl;

            cin>>opcion;
            switch (opcion) {
            case 'A':case 'a':
            {
                displayVehiculosDisponibles();
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
                default:
                    break;
                }
            }



        }while((opcion<'A'||opcion>'E') && (opcion<'a'||opcion>'e'));
    }

    while(opcion!='E'&&opcion!='e');


}

void Cliente::displayVehiculosDisponibles()
{
    bool i=1;
    for(list<Vehiculo>::iterator it = _plataforma->getVehiculos().begin(); it!= _plataforma->getVehiculos().end();it++)
    {
        if(i){
            cout<<"___________________________________________________________________"<<endl
               <<"| Matricula\t|\tLongitud\t|\tLatitud\t|"<<endl;
            i=0;
        }
        if( it->getDisponible())
        {
            cout<<"| "<<it->getMatricula()<<"\t|\t"<<it->getLocalizacion()[1]<<"\t|\t"<<it->getLocalizacion()[0]<<"\t|"<<endl;
        }
    }

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

        if(l!=999999) cout << "El vehiculo más cercano a su posicion es " << itCercano->getMatricula() <<endl;
        else cout << "No disponemos de vehiculos libres"<< endl;
    }
    else cout << "No disponemos de vehiculos libres"<< endl;
}



/*void Cliente::displayCochesCercanos()
                                                        {
                                                            list<Vehiculo>  vehiculosCercanos;
                                                            list<Vehiculo>::iterator itC;
                                                            for(list<Vehiculo>::iterator itC = _plataforma->getVehiculos().begin(); itC!= _plataforma->getVehiculos().end();itC++)
                                                            {
                                                               vehiculosCercanos.push_back(*itC);
                                                            }

                                                            for(list<Vehiculo>::iterator it = vehiculosCercanos.begin(); it!= vehiculosCercanos.end();it++)
                                                            {
                                                                if( !(it->getDisponible()))
                                                                {
                                                                   vehiculosCercanos.remove(*it);
                                                                    it = vehiculosCercanos.begin();
                                                                }


                                                            }

                                                            list<Vehiculo>::iterator it;
                                                            do
                                                            {

                                                                it = cocheCercano(vehiculosCercanos);
                                                                cout << it->getMatricula() <<" a " << distanciaAVehiculo(it->getLocalizacion()) << " unidades"<< endl;
                                                                vehiculosCercanos.remove(*it);

                                                            }
                                                            while(vehiculosCercanos.begin()!=vehiculosCercanos.end());

                                                        }
                                                        */
double Cliente::distanciaAVehiculo(double * localizacion)
{
    return sqrt(pow((_localizacion[1]-localizacion[1]),2)+pow((_localizacion[0]-localizacion[0]),2));

}

