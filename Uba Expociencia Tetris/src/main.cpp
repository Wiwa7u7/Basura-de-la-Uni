#include <raylib.h>
#include "Juego.h"
#include "colores.h"
#include <iostream>

double ultimaActualizacionTiempo = 0;

bool EventTriggered(double intervalo)
{
    double tiempoActual = GetTime();
    if(tiempoActual - ultimaActualizacionTiempo >= intervalo)
    {
        ultimaActualizacionTiempo = tiempoActual;
        return true;
    }
    return false;
}
int main()
{
    InitWindow(500, 620, "Uba Tetris");
    SetTargetFPS(60);

    Font fuente = LoadFontEx("Font/monogram.ttf", 64, 0 , 0);

    Juego juego = Juego();

    while(WindowShouldClose() == false)
    {
        UpdateMusicStream(juego.musica);
        juego.ManejarInput();
        if(EventTriggered(0.2))
        {
            juego.MoverBLoqueAbajo();
        }
        BeginDrawing();
        ClearBackground(azulOscuro);
        DrawTextEx(fuente, "Puntaje", {340, 13}, 38, 2, WHITE);
        DrawTextEx(fuente, "Siguiente", {320, 175}, 38, 2, WHITE);
        if (juego.gameover)
        {
            DrawTextEx(fuente, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, azulClaro);

        char textopuntaje[10];
        sprintf(textopuntaje, "%d", juego.puntaje);
        Vector2 tamanotexto = MeasureTextEx(fuente, textopuntaje, 38, 2);
        DrawTextEx(fuente, textopuntaje, {320 + (170 - tamanotexto.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, azulClaro);
        juego.Dibujo();
        EndDrawing();

    }

    CloseWindow();
}