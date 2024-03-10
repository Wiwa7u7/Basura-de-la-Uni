#pragma once
#include "grid.h"
#include "Bloques.cpp"

class Juego
{
public:
    Juego();
    ~Juego();
    void Dibujo();
    void ManejarInput();
    void MoverBLoqueAbajo();
    bool gameover;
    int puntaje;
    Music musica;

private:
    Grid grid;
    void MoverBLoqueIzquierda();
    void MoverBLoqueDerecha();
    Bloque GetBloqueRandom();
    std::vector<Bloque> Gettodoslosbloques();
    bool EstaelBLoqueAfuera();
    void rotarbloque();
    void  bloquearBloque();
    bool BloqueEntra();
    void Reset();
    void ActualizarPuntaje(int lineaslimpiadas , int puntosmoverabajo);
    std::vector<Bloque> bloques;
    Bloque bloqueActual;
    Bloque bloqueSiguiente;
    Sound sonidorotar;
    Sound sonidolimpiar;
};