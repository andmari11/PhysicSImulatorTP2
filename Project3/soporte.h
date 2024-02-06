#pragma once

#ifndef fichas.h
    
    #include "fichas.h"

#endif // !"fichas.h"

#ifndef jugadas.h

    #include "jugadas.h"

#endif // !"jugadas.h"

struct tSoporte {

    tFicha** array;
    int capacidad = 8, contador = 0;
};

//elimina las fichas del soporte que se encuentran en la jugada, ademas de modificar la capacidad del soporte
void eliminaFichas(tSoporte& soporte, tJugada& jugada);

//muestra el soporte
void mostrar(const tSoporte& soporte);

//ordena por numero el soporte
void ordenarPorNum(tSoporte& soporte);

//ordena por color el soporte
void ordenarPorColor(tSoporte& soporte);

//juzga si la jugada es valida
int nuevaJugada(tSoporte& soporte, tJugada& jugada);

//intenta colocar una ficha en el tablero
void nuevaFicha(tFicha* ficha, tSoporte& soporte);

//muestra las posibles escaleras de un soporte
void mostrarEscaleras(tSoporte& soporte);

//muestra las posibles series de un soporte
void mostrarSeries(tSoporte& soporte);

//sugiere escaleras o series de un soporte
void sugerir(tSoporte& soporte);