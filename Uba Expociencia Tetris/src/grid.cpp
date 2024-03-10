#include "grid.h"
#include <iostream>
#include "colores.h"

Grid::Grid()
{
    numFilas = 20;
    numColu = 10;
    tamanoCasilla = 30;
    Initialize();
    colores = GetColorCasilla();
}

void Grid::Initialize()
{
    for (int filas = 0; filas < numFilas; filas++)
    {
        for (int columna = 0; columna < numColu; columna++)
        {
            grid[filas][columna] = 0;
        }
    }
}

void Grid::Print()
{
    for (int filas = 0; filas < numFilas; filas++)
    {
        for (int columna = 0; columna < numColu; columna++)
        {
            std::cout << grid[filas][columna] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Dibujo()
{
    for(int filas = 0; filas < numFilas; filas++)
    {
        for(int columna = 0 ; columna < numColu; columna++)
        {
            int valorCasilla = grid[filas][columna];
            DrawRectangle(columna * tamanoCasilla+11 , filas * tamanoCasilla+11 , tamanoCasilla-1 , tamanoCasilla-1 , colores[valorCasilla]);
        }
    }
}

bool Grid::EslaCasillafuera(int fila, int columna)
{
    if (fila >= 0 && fila < numFilas && columna >= 0 && columna < numColu)
    {
        return false;
    }
    return true;
}

bool Grid::estaLaCeldaVacia(int filas, int columna)
{
    if(grid[filas][columna] == 0)
    {
        return true;
    }
    return false;
}

int Grid::limpiarCasillasCompletas()
{
    int completado = 0;
    for(int filas = numFilas-1;filas >= 0;filas--)
    {
        if(laFilaEstaFull(filas))
        {
            limpiarFila(filas);
            completado++;
        }
        else if (completado > 0)
        {
            MoverFilaAbajo(filas, completado);
        }
    }
    return completado;
}

bool Grid::laFilaEstaFull(int filas)
{
    for(int columnas = 0; columnas < numColu; columnas++)
    {
        if(grid[filas][columnas] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::limpiarFila(int filas)
{
    for (int columnas = 0; columnas < numColu; columnas++)
    {
        grid[filas][columnas] = 0;
    }
}

void Grid::MoverFilaAbajo(int filas, int numFilas)
{
    for(int columnas = 0; columnas < numColu; columnas++)
    {
        grid[filas + numFilas][columnas] = grid[filas][columnas];
        grid[filas][columnas] = 0;
    }
}
