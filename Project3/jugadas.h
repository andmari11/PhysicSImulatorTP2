#pragma once

#ifndef fichas.h

	#include "fichas.h"

#endif // !"fichas.h"

typedef tFicha** tJugada;

//muestra jugada
void mostrar(const tJugada& jugada);

//busca una ficha en una jugada y devuelve el inice si esta o -1 si no lo esta
int buscar(tFicha**& jugada, tFicha*& ficha);

//inicializa una jugada
void iniJugada(tJugada& jugada);

//pone una ficha en la jugada, agrandando su tamaño si es necesario
bool ponerFicha(tJugada& jugada, tFicha* ficha);

//mira que no se repita el color en una serie
bool colorRepetido(const tJugada& jugada, tFicha* ficha, const int numFichas);

//resetea de numero de las fichas de una jugada a -1
void resetJugada(tJugada& jugada);

//elimina la jugada
void delJugada(tJugada& jugada);

//chequea si una serie es valida
bool serieValida(const tJugada& jugada, const int numfichas);

//chequea si una escalera es valida
bool escaleraValida(const tJugada& jugada, const int numfichas);

