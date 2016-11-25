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
    VIP(Plataforma *_plataforma);
    void reservar();
    ~VIP(){}
};
#endif // VIP_H
