#pragma once
#include <iostream>
#include <fstream>

using namespace std;

enum tColor { rojo, verde, azul, amarillo, blanco };

//cambia el color del texto dependiendo del color de la ficha
void colorTexto(const tColor color);