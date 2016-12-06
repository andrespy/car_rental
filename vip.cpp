#include "vip.h"
#include "reserva.h"
#include "plataforma.h"

//
//
//     **********    VIP    *******
//
//



VIP::VIP(Plataforma *plataforma): Cliente(plataforma)
{


}
VIP::VIP(string id,Plataforma *plataforma):Cliente(id, plataforma)
{

}

VIP::VIP(string id,Plataforma *plataforma,double loc[]):Cliente(id, plataforma,loc)
{

}




void VIP::reservar()
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


    Reserva reserva(_id,_plataforma->buscarVehiculo(matricula)->getMatricula());
    reserva.pideFecha();
    char opcion;
    do{
        cout<<"Dado que es VIP tiene derecho a bloquear el vehiculo 5 horas antes. Desea hacerlo (S/N):"<<endl;
        cin >> opcion;
    }while(opcion!='s' && opcion!='S' && opcion!='N' && opcion!='n');
    if(opcion == 's' || opcion == 'S')
    {
        reserva.getInicio()=reserva.getInicio().addSecs(-3600*5);
    }
    _plataforma->getReservas().push_back(reserva);
    _plataforma->buscarVehiculo(matricula)->setDisponible(0);
    cout<<"¡Enhorabuena! Ha reservado el vehiculo "
       <<reserva.getMatricula()
      <<endl;



}
