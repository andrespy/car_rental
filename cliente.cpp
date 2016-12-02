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

double * Cliente::localizarVehiculos()
{

}

Vehiculo Cliente::vehiculoCercano()
{

}


void Cliente::reservar()
{   /*unsigned int opcionvehiculo;

    do{
        cout << "Los 10 vehiculos disponibles más cercanos a usted son:"<<endl;
        // VehiculosCercanosDisp(this->getLocalizacion,10);
        cout << "Introduzca el numero del vehiculo que desea reservar: (Si desea cancelar la operacion escriba c)";
        cin  >> opcionvehiculo;
    }
    while(opcionvehiculo>10 || opcionvehiculo<1 && opcionvehiculo != 'c');*/


    //QDateTime fin(QDateTime.currentDateTime());
    /*
    cout<< "Introduce el tiempo de uso en dias:"<<endl;
    unsigned int dias;

    if(!(opcionvehiculo>10 || opcionvehiculo<1))
    {   // VehiculoCercano(this->getLocalizacion,opcionvehiculo); http://stackoverflow.com/questions/9706517/sort-a-vector-of-objects-by-an-objects-attribute
        //   Reserva reserva(this->getID(),QDateTime.currentDateTime(), fin,VehiculoCercano(this->getLocalizacion,opcionvehiculo)->getMatricula);
        //this->_plataforma->getReservas().push_back(reserva);
    }
    */
    string matricula;
    do
    {
        do
        {
            cout << "Introduce la matrícula del coche que desea reservar: ";
            cin >> matricula;
            cout<<endl;
            if(!_plataforma->esVehiculo(matricula)) cout << "No existe dicho vehiculo."<<endl;
            else if(!_plataforma->buscarVehiculo(matricula)->getDisponible())
                cout<<"Dicho vehiculo no esta disponible en estos momentos."<<endl;

        }
        while(!_plataforma->esVehiculo(matricula));
    }
    while(!_plataforma->buscarVehiculo(matricula)->getDisponible());

    unsigned int dias;


    cout << "Introduzca el numero de dias que desea que dure la reserva: ";
    cin>> dias;

    QDateTime inicio = QDateTime::currentDateTime();
    QDateTime fin= inicio.addDays(int(dias));


    Reserva reserva(_id,inicio,fin ,_plataforma->buscarVehiculo(matricula)->getMatricula());
    _plataforma->getReservas().push_back(reserva);
    _plataforma->buscarVehiculo(matricula)->setDisponible(0);
    cout<<"¡Enhorabuena! Ha reservado el vehiculo " <<reserva.getMatricula()
       <<". Su reserva comprende hasta el día "<<fin.date().day()<<" de "<<fin.date().month()<< " de " << fin.date().year()<< " a las "<< fin.time().hour()<<":"<<fin.time().minute()<<endl;


}

void Cliente::historial()
{
    cout << "Sus reservas hasta la fecha son: "<<endl;
    for(list <Reserva>::iterator it =_plataforma->getReservas().begin();it!=_plataforma->getReservas().end();it++)
    {
        if(it->getId()==_id)
        {
            cout << "\tEl dia " <<it->getInicio().date().day()<< " del " <<it->getInicio().date().month() <<"de"<<it->getInicio().date().year() <<" reservo el vehiculo con matricula "<< it->getMatricula()<<endl;
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
            case 'A':
            {
                //this->plataforma.displayVehiculos();
                break;
            case 'B':
                {
                    displayVehiculoCercano();
                    break;
                }
                case 'C':
                {
                    reservar();
                    break;
                }
                case 'D':
                {
                    historial();
                    break;
                }
                default:
                    break;
                }
            }



        }while(opcion<'A'||opcion>'E');
    }

    while(opcion!='E');


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

