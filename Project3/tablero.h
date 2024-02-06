#pragma once

#ifndef soporte.h

    #include "soporte.h"
#endif 

struct tTablero {

    int contador = 0;
    tJugada* jugadas;
};

//elimina el tablero
void delTablero(tTablero& tablero);

//permite al jugador colocar fichas en el tablero y devuelve el exito del jugador
bool jugar(tTablero& tablero, tSoporte& soporte);

//muestra el tablero
void mostrar(const tTablero& tablero);

