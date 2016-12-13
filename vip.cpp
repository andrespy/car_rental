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
        cout << "Introduce la matricula del coche que desea reservar: ";
        cin >> matricula;
        cout<<endl;
        if(!_plataforma->esVehiculo(matricula)) cout << "No existe dicho vehiculo."<<endl;

    }
    while(!_plataforma->esVehiculo(matricula));



    Reserva reserva(_id,matricula);
    do{

        reserva.pideFecha();
        if(colisionReserva(reserva)) cerr << "Error de colision de reservas"<<endl;
    }while (colisionReserva(reserva));
    Reserva pruebaReserva(reserva);
    pruebaReserva.getInicio().time().setHMS(pruebaReserva.getInicio().time().hour()-5,pruebaReserva.getInicio().time().minute(),pruebaReserva.getInicio().time().second());
    if(!colisionReserva(pruebaReserva))
    {
        char opcion;
        do{
            cout<<"Dado que es VIP tiene derecho a bloquear el vehiculo 5 horas antes. Desea hacerlo (S/N):"<<endl;
            cin >> opcion;
        }while(opcion!='s' && opcion!='S' && opcion!='N' && opcion!='n');
        if(opcion == 's' || opcion == 'S')
        {
            reserva.getInicio()=reserva.getInicio().addSecs(-3600*5);
        }
    }
    else cout <<"Sabemos que es VIP pero dicho vehiculo no se puede bloquear 5 horas antes puesto que esta reservado"<<endl;
    _plataforma->getReservas().push_back(reserva);
    _plataforma->buscarVehiculo(matricula)->setDisponible(0);
    cout<<"¡Enhorabuena! Ha reservado el vehiculo "
       <<reserva.getMatricula()
      <<endl;



}
