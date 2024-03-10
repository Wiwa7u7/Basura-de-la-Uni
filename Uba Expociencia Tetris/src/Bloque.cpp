#include "bloque.h"

Bloque::Bloque()
{
    tamanoCasilla = 30;
    estadoRotacion = 0;
    colores = GetColorCasilla();
    filaOffset = 0;
    columnaOffset = 0;
}

void Bloque::Dibujo(int offsetX,int offsetY)
{
    std::vector<Posicion> losas = GetposicionCasilla();
    for(Posicion item: losas)
    {
        DrawRectangle(item.columna * tamanoCasilla + offsetX , item.filas * tamanoCasilla + offsetY , tamanoCasilla - 1  , tamanoCasilla - 1  , colores[id] );
    }
}

void Bloque::Mover(int filas , int columnas)
{
    filaOffset += filas;
    columnaOffset += columnas;
}

std::vector<Posicion> Bloque::GetposicionCasilla()
{
    std::vector<Posicion> losas = casillas[estadoRotacion];
    std::vector<Posicion> losasmovidas;
    for(Posicion item: losas)
    {
        Posicion newPos = Posicion(item.filas + filaOffset,item.columna + columnaOffset);
        losasmovidas.push_back(newPos);
    }
    return losasmovidas;
}
void Bloque::Rotar()
{
    estadoRotacion++;
    if(estadoRotacion == (int)casillas.size())
    {
        estadoRotacion = 0;
    }
}
void Bloque::deshacerRotacion()
{
    estadoRotacion --;
    if(estadoRotacion == -1)
    {
        estadoRotacion = casillas.size() - 1;
    }
}