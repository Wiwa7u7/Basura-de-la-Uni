#include "colores.h"

const Color grisOscuro = {26, 31, 40, 255};
const Color verde = {47, 230, 23, 255};
const Color rojo = {232, 18, 18, 255};
const Color naranja = {226, 116, 17, 255};
const Color amarillo = {237, 234, 4, 255};
const Color morado = {166, 0, 247, 255};
const Color cian = {21, 204, 209, 255};
const Color azul = {13, 64, 216, 255};
const Color azulClaro = {59, 85, 162, 255};
const Color azulOscuro = {44, 44, 127, 255};

std::vector<Color> GetColorCasilla()
{
    return{grisOscuro, verde , rojo , naranja , amarillo , morado ,  cian , azul};
}