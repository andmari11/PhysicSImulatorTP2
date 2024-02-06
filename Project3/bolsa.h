#pragma once
#include "fichas.h"

struct tBolsa {

    int contador = 0;
    tFicha*** fichas;
};

//muuestra la bolsa
void mostrar(const tBolsa& bolsa);

//inicializa la bolsa con los colores y numeros correspondientes
void inicializarBolsa(tBolsa& bolsa);

//elimina la bolsa
void delBolsa(tBolsa& bolsa);

//devuelve una ficha disponible aleatoria de la bolsa
tFicha* robar(tBolsa& bolsa);