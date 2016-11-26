#include "usuario.h"

#include "vehiculo.h"
#include "plataforma.h"
Usuario::Usuario(Plataforma *plat)
{
    _id = "";
    _plataforma = plat;

}
Usuario::Usuario()
{
    _id = "";
    _plataforma = NULL;

}

Usuario::Usuario(string id , Plataforma *plat)
{
    _id = id;
    _plataforma= plat;

}



/*Plataforma * Usuario::getPlataforma()
{
    return _plataforma;
}*/

Usuario & Usuario::operator=(Usuario usr)
{
    _id = usr._id;
    return *this;
}


string Usuario::getID()
{
    return _id;
}

void Usuario::setID(string id)
{
    //validar id
    _id = id;
}






