#include "Juego.h"
#include <random>

Juego::Juego()
{
    grid = Grid();
    bloques = Gettodoslosbloques();
    bloqueActual = GetBloqueRandom();
    bloqueSiguiente = GetBloqueRandom();
    gameover = false;
    puntaje = 0;
    InitAudioDevice();
    musica = LoadMusicStream("Sonidos/mia.mp3");
    PlayMusicStream(musica);
    sonidorotar = LoadSound("Sonidos/rotar.mp3");
    sonidolimpiar = LoadSound("Sonidos/limpiar.mp3");
}

Juego::~Juego()
{
    UnloadSound(sonidolimpiar);
    UnloadSound(sonidorotar);
    UnloadMusicStream(musica);
    CloseAudioDevice();
}

Bloque Juego::GetBloqueRandom()
{
    if(bloques.empty())
    {
        bloques = Gettodoslosbloques();
    }
    int randomIndex = rand() % bloques.size();
    Bloque bloque = bloques[randomIndex];
    bloques.erase(bloques.begin() + randomIndex);
    return bloque;
} 

std::vector<Bloque>Juego::Gettodoslosbloques()
{
    return {IBloque(), OBloque(),ZBloque(), JBloque(), SBloque(), TBloque(), LBloque()};
}

void Juego::Dibujo()
{
    grid.Dibujo();
    bloqueActual.Dibujo(11,11);
    switch (bloqueSiguiente.id)
    {
    case 3:
    bloqueSiguiente.Dibujo(255,290);
        break;
    case 4:
        bloqueSiguiente.Dibujo(255,280);
        break;
    default:
        bloqueSiguiente.Dibujo(270,270);
        break;
    }
}

void Juego::ManejarInput()
{
    int teclaPresionada = GetKeyPressed();
    if(gameover && teclaPresionada != 0)
    {
        gameover = false;
        Reset();
    }
    switch(teclaPresionada)
    {
    case KEY_A:
        MoverBLoqueIzquierda();
        break;
    case KEY_D:
        MoverBLoqueDerecha();
        break;
    case KEY_S:
    MoverBLoqueAbajo();
    ActualizarPuntaje(0,1);
    break;
    case KEY_W:
        rotarbloque();
        break;
    }
}

void Juego::MoverBLoqueIzquierda()
{
    if(!gameover)
    {
    bloqueActual.Mover(0,-1);
    if(EstaelBLoqueAfuera() || BloqueEntra() == false)
    {
        bloqueActual.Mover(0,1);
    }
    }
}
void Juego::MoverBLoqueDerecha()
{
    if(!gameover)
    {
    bloqueActual.Mover(0,1);
     if(EstaelBLoqueAfuera() || BloqueEntra() == false)
    {
        bloqueActual.Mover(0,-1);
    }
    }
}
void Juego::MoverBLoqueAbajo()
{
    if(!gameover)
    {
    bloqueActual.Mover(1,0);
     if(EstaelBLoqueAfuera() || BloqueEntra() == false)
    {
        bloqueActual.Mover(-1,0);
        bloquearBloque();
    }
    }
}

bool Juego::EstaelBLoqueAfuera()
{
    std::vector<Posicion> losas = bloqueActual.GetposicionCasilla();
    for(Posicion item: losas)
    {
        if (grid.EslaCasillafuera(item.filas, item.columna))
        {
            return true;
        }
    }
    return false;
}

void Juego::rotarbloque()
{
    if(!gameover)
    {
    bloqueActual.Rotar();
    if(EstaelBLoqueAfuera() || BloqueEntra() == false)
    {
        bloqueActual.deshacerRotacion();
    }
    else
    {
        PlaySound(sonidorotar);
    }
    }
}

void Juego::bloquearBloque()
{
    std::vector<Posicion> losas = bloqueActual.GetposicionCasilla();
    for(Posicion item: losas)
    {
        grid.grid[item.filas][item.columna] = bloqueActual.id;
    }
    bloqueActual = bloqueSiguiente;
    if(BloqueEntra() == false)
    {
        gameover = true;
    }
    bloqueSiguiente = GetBloqueRandom();
    int filasLimpiadas = grid.limpiarCasillasCompletas();
    if(filasLimpiadas > 0 )
    {
        PlaySound(sonidolimpiar);
        ActualizarPuntaje(filasLimpiadas, 0);
    }
}

bool Juego::BloqueEntra()
{
   std::vector<Posicion> losas = bloqueActual.GetposicionCasilla();
   for(Posicion item:losas)
   {
    if(grid.estaLaCeldaVacia(item.filas, item.columna) == false)
    {
        return false;
    }
   }
   return true;
}

void Juego::Reset()
{
    grid.Initialize();
    bloques = Gettodoslosbloques();
    bloqueActual = GetBloqueRandom();
    bloqueSiguiente = GetBloqueRandom();
    puntaje = 0;
}

void Juego::ActualizarPuntaje(int lineaslimpiadas, int puntosmoverabajo)
{
    switch(lineaslimpiadas)
    {
        case 1:
            puntaje += 100;
            break;
        case 2:
            puntaje += 300;
            break;
        case 3:
            puntaje +=500;
            break;
        default:
            break;
    }
    puntaje += puntosmoverabajo;
}
