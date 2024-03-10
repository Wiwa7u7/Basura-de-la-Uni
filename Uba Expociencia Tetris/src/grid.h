#pragma once 
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void Initialize(); 
    void Print();
    void Dibujo();
    bool EslaCasillafuera(int fila, int columna);
    bool estaLaCeldaVacia(int filas, int columna);
    int limpiarCasillasCompletas();
    int grid[20][10];   
private:
    bool laFilaEstaFull(int filas);
    void limpiarFila(int filas);
    void MoverFilaAbajo(int filas, int numFilas);
    int numFilas;
    int numColu;
    int tamanoCasilla;
    std::vector<Color> colores;
};