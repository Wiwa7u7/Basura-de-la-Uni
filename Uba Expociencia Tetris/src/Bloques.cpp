#include "bloque.h"
#include "posicion.h"

class LBloque :public Bloque{
public:
    LBloque(){
        id = 1;
        casillas[0] = {Posicion(0,2), Posicion(1, 0), Posicion(1,1), Posicion(1, 2)};
        casillas[1] = {Posicion(0,1), Posicion(1, 1), Posicion(2,1), Posicion(2, 2)};
        casillas[2] = {Posicion(1,0), Posicion(1, 1), Posicion(1,2), Posicion(2, 0)};
        casillas[3] = {Posicion(0,0), Posicion(0, 1), Posicion(1,1), Posicion(2, 1)};
        Mover (0,3);
    }
};
class JBloque : public Bloque
{
public:
    JBloque()
    {
        id = 2;
        casillas[0] = {Posicion(0, 0), Posicion(1, 0), Posicion(1, 1), Posicion(1, 2)};
        casillas[1] = {Posicion(0, 1), Posicion(0, 2), Posicion(1, 1), Posicion(2, 1)};
        casillas[2] = {Posicion(1, 0), Posicion(1, 1), Posicion(1, 2), Posicion(2, 2)};
        casillas[3] = {Posicion(0, 1), Posicion(1, 1), Posicion(2, 0), Posicion(2, 1)};
        Mover (0,3);
    }
};

class IBloque : public Bloque
{
public:
    IBloque()
    {
        id = 3;
        casillas[0] = {Posicion(1, 0), Posicion(1, 1), Posicion(1, 2), Posicion(1, 3)};
        casillas[1] = {Posicion(0, 2), Posicion(1, 2), Posicion(2, 2), Posicion(3, 2)};
        casillas[2] = {Posicion(2, 0), Posicion(2, 1), Posicion(2, 2), Posicion(2, 3)};
        casillas[3] = {Posicion(0, 1), Posicion(1, 1), Posicion(2, 1), Posicion(3, 1)};
        Mover (-1,3);
    }
};
class OBloque : public Bloque
{
public:
    OBloque()
    {
        id = 4;
        casillas[0] = {Posicion(0, 0), Posicion(0, 1), Posicion(1, 0), Posicion(1, 1)};
        Mover (0,4);
    }
};

class SBloque : public Bloque
{
public:
    SBloque()
    {
        id = 5;
        casillas[0] = {Posicion(0, 1), Posicion(0, 2), Posicion(1, 0), Posicion(1, 1)};
        casillas[1] = {Posicion(0, 1), Posicion(1, 1), Posicion(1, 2), Posicion(2, 2)};
        casillas[2] = {Posicion(1, 1), Posicion(1, 2), Posicion(2, 0), Posicion(2, 1)};
        casillas[3] = {Posicion(0, 0), Posicion(1, 0), Posicion(1, 1), Posicion(2, 1)};
        Mover (0,3);
    }
};

class TBloque : public Bloque
{
public:
    TBloque()
    {
        id = 6;
        casillas[0] = {Posicion(0, 1), Posicion(1, 0), Posicion(1, 1), Posicion(1, 2)};
        casillas[1] = {Posicion(0, 1), Posicion(1, 1), Posicion(1, 2), Posicion(2, 1)};
        casillas[2] = {Posicion(1, 0), Posicion(1, 1), Posicion(1, 2), Posicion(2, 1)};
        casillas[3] = {Posicion(0, 1), Posicion(1, 0), Posicion(1, 1), Posicion(2, 1)};
        Mover (0,3);
    }
};

class ZBloque : public Bloque
{
public:
    ZBloque()
    {
        id = 7;
        casillas[0] = {Posicion(0, 0), Posicion(0, 1), Posicion(1, 1), Posicion(1, 2)};
        casillas[1] = {Posicion(0, 2), Posicion(1, 1), Posicion(1, 2), Posicion(2, 1)};
        casillas[2] = {Posicion(1, 0), Posicion(1, 1), Posicion(2, 1), Posicion(2, 2)};
        casillas[3] = {Posicion(0, 1), Posicion(1, 0), Posicion(1, 1), Posicion(2, 0)};
        Mover (0,3);
    }
};