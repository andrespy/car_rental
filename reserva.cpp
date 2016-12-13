#include "reserva.h"

Reserva::Reserva()
{

    _inicio = QDateTime();
    _matricula = "";
    _id ="";
    _fin = QDateTime();

}

Reserva::Reserva(const Reserva &reserva)
{
    _inicio = reserva._inicio;
    _matricula = reserva._matricula;
    _id = reserva._id;
    _fin = reserva._fin;

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
    }while(opcion!='s' && opcion!='S' && opcion!='n' && opcion!='N');
    if (opcion=='S'||opcion=='s')
        _inicio=QDateTime::currentDateTime();
    else if(opcion=='N'||opcion=='n')
    {
        int fecha[5];
        do{
            do{
                cout<<"Escriba el ano en el que INICIAR la reserva."<<endl;
                cin>>fecha[0];
            }while(fecha[0]<QDateTime::currentDateTime().date().year());
            do{
                cout<<"Escriba el mes, (1-12) en el que INICIAR la reserva."<<endl;
                cin>>fecha[1];
            }while(fecha[1]<1 || fecha[1]>12);

            do{
                cout<<"Escriba el dia (1-30/31) en el que INICIAR la reserva."<<endl;
                cin>>fecha[2];
            }while(fecha[2]<1 || fecha[2]>31);

            do{
                cout<<"Escriba la hora, (0-23) en el que INICIAR la reserva."<<endl;
                cin>>fecha[3];
            }while(fecha[3]>23||fecha[3]<0);

            do{
                cout<<"Escriba el minuto, (0-59) en el que INICIAR la reserva."<<endl;
                cin>>fecha[4];
            }while(fecha[4]<0||fecha[4]>59);


            inicio = QDateTime(QDate(fecha[0],fecha[1],fecha[2]),QTime(fecha[3],fecha[4],0,0));
        }while(!inicio.isValid());
    }



    int fecha1[5];
    do{
        do{
        cout<<"Escriba el ano en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[0];
        }while(fecha1[0]<QDateTime::currentDateTime().date().year());

        do{
        cout<<"Escriba el mes, (1-12) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[1];
        }while(fecha1[1]<1 || fecha1[1]>12);

        do{
        cout<<"Escriba el dia, (1-30/31) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[2];
        }while(fecha1[2]<1 || fecha1[2]>31);

        do{
        cout<<"Escriba la hora, (0-23) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[3];
        }while(fecha1[3]>23||fecha1[3]<0);

        do{
        cout<<"Escriba el minuto, (0-59) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha1[4];
         }while(fecha1[4]<0||fecha1[4]>59);

        final=  QDateTime(QDate(fecha1[0],fecha1[1],fecha1[2]),QTime(fecha1[3],fecha1[4],0,0));

        if(final<inicio) cerr<<"La fecha de fin de reserva no puede ser previa a la de inicio."<<endl;

    }while(!final.isValid() || final<inicio);

    if(opcion=='N'||opcion=='n') _inicio = inicio;
    _fin = final;


    cout<<"Inicio:\t"<<_inicio.toString("HH:mm 'de' dddd dd 'de' MMMM 'del' yyyy").toStdString()<<endl<<endl;

    cout<<"Fin:\t"<<final.toString("HH:mm 'de' dddd dd 'of' MMMM 'of' yyyy").toStdString()<<endl<<endl;
    cout<<"El coste de la operacion asciende a "<< precioReserva(_inicio, _fin)<<" Euros"<<endl<<endl;

}
