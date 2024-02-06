#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

#include "soportes.h"
#include "bolsa.h"
#include "tablero.h"


#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

using namespace std;
const int NUM_FICHAS = 8;

//devuelve una opcion valida del menu elegida por el usuario
int menu();

/*COLORES:
	-colortexto

FICHAS:
	-mostrar

BOLSA:
	-mostrar
	-inicializarBolsa
	-delBolsa
	-robar

JUGADAS:
	-mostrar
	-buscar
	-inijugada
	-ponerFicha
	-colorRepetido
	-resetJugada
	-delJugada

TABLERO:
	-mostrar
	-jugar
	-delTablero

SOPORTE:
	-eliminaFichas
	-mostrar
	-ordenarPorNum
	-ordenarPorColor
	-nuevaJugada
	-nuevaFicha
	-mostrarEscaleras
	-mostrarSeries
	-sugerir

SOPORTES:

	-repartir
	-iniSoporte
	-delSoportes
*/