#pragma once
#include <vector>
#include <map>
#include "posicion.h"
#include "colores.h"

class Bloque
{
public:
    Bloque();
    void Dibujo(int offsetX , int offsetY);
    void Mover(int filas, int columnas);
    std::vector<Posicion> GetposicionCasilla();
    void Rotar();
    void deshacerRotacion();
    int id;
    std::map<int, std::vector<Posicion>> casillas;
private:
    int tamanoCasilla;
    int estadoRotacion;
    std::vector<Color> colores;
    int filaOffset;
    int columnaOffset;
};