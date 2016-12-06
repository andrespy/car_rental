#ifndef VIP_H
#define VIP_H
#include "cliente.h"

//
//
//     **********    VIP    *******
//
//

class VIP : public Cliente
{
public:
    VIP(Plataforma *plataforma);
    VIP(string id, Plataforma *plataforma);
    VIP(string id,Plataforma *plataforma,double loc[]);
    void reservar();
    ~VIP(){}
};
#endif // VIP_H
