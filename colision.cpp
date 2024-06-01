#include "colision.h"

colision::colision()
{
    //ctor
}


bool colision::colisionEnCurso(colision& obj) const
{
    return getBounds().intersects(obj.getBounds());
}

