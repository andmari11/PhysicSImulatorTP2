#pragma once
#include "colores.h"
#include <iomanip>

struct tFicha {

    int num = -1;
    tColor color;
};

//muestra una ficha
void mostrar(tFicha* ficha);