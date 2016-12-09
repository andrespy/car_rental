#include "reserva.h"

Reserva::Reserva()
{

    _inicio = QDateTime();
    _matricula = "";
    _id ="";
    _fin = QDateTime();

}
Reserva::Reserva(const string& id,const string & matricula)
{
    _inicio = QDateTime();
    _matricula = matricula;
    _id = id;
    _fin = QDateTime();

}

void Reserva::setId(string id)
{
    _id = id;
}
void Reserva::setMatricula(string matricula)
{
    _matricula = matricula;
}

Reserva::Reserva(const string &id , const QDateTime & inicio , const QDateTime & fin , const string & matricula)
{

    _inicio = inicio;
    _fin = fin;
    _id               =   id;
    _matricula        =   matricula;

}
QDateTime Reserva::getInicio()
{
    return _inicio;
}
void Reserva::setInicio(QDateTime inicio)
{
    _inicio = inicio;
}
QDateTime Reserva::getFin()
{
    return _fin;

}
void Reserva::setFin(QDateTime fin)
{
    _fin = fin;

}


Reserva & Reserva::operator=(Reserva reserva)
{
    _inicio          = reserva._inicio;
    _fin             = reserva._fin;
    _matricula       = reserva._matricula;
    _id              = reserva._id;

    return *this;
}

Reserva::~Reserva()
{

}


float Reserva::precioReserva(QDateTime inicio, QDateTime fin)
{
    int segundos = inicio.secsTo(fin);
    float prize = float(segundos) * 0.19/60;
    return prize;
}

void Reserva::pideFecha()
{   char opcion;
    cout<<"Elija una fecha para el inicio"<<endl;
    QDateTime inicio;
    QDateTime final;
    do{
        cout<<"¿Desea reservarlo para ahora mismo? (S o N)"<<endl;
        cin>>opcion;
        if (opcion=='S'||opcion=='s')
            _inicio=QDateTime::currentDateTime();
        else if(opcion=='N'||opcion=='n')
        {
            int fecha[5];
            do{
                cout<<"Escriba el ano en el que INICIAR la reserva."<<endl;
                cin>>fecha[0];
                cout<<"Escriba el mes, (1-12) en el que INICIAR la reserva."<<endl;
                cin>>fecha[1];
                cout<<"Escriba el dia (1-30/31) en el que INICIAR la reserva."<<endl;
                cin>>fecha[2];
                cout<<"Escriba la hora, (0-23) en el que INICIAR la reserva."<<endl;
                cin>>fecha[3];
                cout<<"Escriba el minuto, (0-59) en el que INICIAR la reserva."<<endl;
                cin>>fecha[4];

                inicio = QDateTime(QDate(fecha[0],fecha[1],fecha[2]),QTime(fecha[3],fecha[4],0,0));
            }while(!inicio.isValid() || inicio<QDateTime::currentDateTime());
        }
    }while(opcion!='s' && opcion!='S' && opcion!='n' && opcion!='N');


    int fecha1[5];
    do{
        cout<<"Escriba el ano en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[0];
        cout<<"Escriba el mes, (1-12) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[1];
        cout<<"Escriba el dia, (1-30/31) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[2];
        cout<<"Escriba la hora, (0-23) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[3];
        cout<<"Escriba el minuto, (0-59) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[4];

        final=  QDateTime(QDate(fecha1[0],fecha1[1],fecha1[2]),QTime(fecha1[3],fecha1[4],0,0));
    }while(!final.isValid() || final<inicio);

    if(opcion=='N'||opcion=='n') _inicio = inicio;
    _fin = final;

    QString iTime = _inicio.toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy");
    cout<<"Inicio:\t"<<iTime.toStdString()<<endl<<endl;
    QString fTime = final.toString("HH:mm 'of' dddd dd 'of' MMMM 'of' yyyy");
    cout<<"Fin:\t"<<fTime.toStdString()<<endl<<endl;
    cout<<"El coste de la operacion asciende a "<< precioReserva(_inicio, _fin)<<" Euros"<<endl<<endl;

}
