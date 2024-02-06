#include "jugadas.h"

#ifndef const int NUM_FICHAS

    const int NUM_FICHAS = 8;

#endif // !const int NUM_FICHAS

void mostrar(const tJugada& jugada) {

    for (int i = 0; i < NUM_FICHAS + 1; i++) {

        if (jugada[i] != NULL and jugada[i]->num != -1) {

            mostrar(jugada[i]);
        }

    }
}

int buscar(tJugada& jugada, tFicha*& ficha) {

    int contador = 0, indice;
    bool final = false;

    while (!final) {
        //se llega al final de la jugada
        if (jugada[contador]->num == -1) {

            final = true;
            indice = -1;
        }

        //se encuentra la ficha
        else if (jugada[contador]->color == ficha->color and jugada[contador]->num == ficha->num) {

            final = true;
            indice = contador;
        }
        // no es la ficha que buscamos
        else {

            contador++;
        }
    }

    return indice;

}

void iniJugada(tJugada& jugada) {

    jugada = new tFicha * [NUM_FICHAS + 1];
    for (int i = 0; i < NUM_FICHAS + 1; i++) {

        jugada[i] = new tFicha;
        jugada[i]->num = -1;

    }


}

bool ponerFicha(tJugada& jugada, tFicha* ficha) {

    int contadorJugada = 0;
    bool exito = false, ascendente = false;

    //cuenta cuantas fichas hay en la jugada
    while (jugada[contadorJugada]->num != -1) {

        contadorJugada++;
    }

    //mira a ver si es una serie o una escalera
    if (jugada[0]->num == jugada[1]->num) {

        //es una serie, por lo q si tiene el mismo numero q el resto la jugada es valida
        if (jugada[0]->num == ficha->num and contadorJugada < 4 and !colorRepetido(jugada, ficha, contadorJugada)) {

            jugada[contadorJugada]->color = ficha->color;
            jugada[contadorJugada]->num = ficha->num;
            exito = true;
        }

    }

    else {

        //es una escalera por lo que la comparamos con la ultima y la primera ficha
        if (jugada[0]->color == ficha->color) {

            int resta;

            resta = jugada[0]->num - jugada[1]->num;

            //se coloca al principio de la escalera
            if (resta == ficha->num - jugada[0]->num) {

                for (int i = contadorJugada; i > 0; i--) {

                    jugada[i]->color = jugada[i - 1]->color;
                    jugada[i]->num = jugada[i - 1]->num;
                }

                jugada[0]->color = ficha->color;
                jugada[0]->num = ficha->num;
                exito = true;
            }

            //se coloca al final
            else if (resta == jugada[contadorJugada - 1]->num - ficha->num) {

                jugada[contadorJugada]->color = ficha->color;
                jugada[contadorJugada]->num = ficha->num;
                exito = true;
            }

        }

    }
    return exito;
}

bool colorRepetido(const tJugada& jugada, tFicha* ficha, const int numFichas) {
    bool repetidoColor = false;

    for (int i = 0; i < numFichas; i++) {

        //se ha repetido el color
        if (ficha->color == jugada[i]->color) {

            repetidoColor = true;
        }
    }

    return repetidoColor;
}

void resetJugada(tJugada& jugada) {
    int contador = 0;

    //vuelve a poner las fichas con numero -1, es decir que quedan libres
    while (contador < NUM_FICHAS + 1 and jugada[contador]->num != -1) {

        jugada[contador]->num = -1;

        contador++;
    }

}

void delJugada(tJugada& jugada) {

    for (int i = 0; i < NUM_FICHAS + 1; i++) {

        //borra cada ficha
        delete[] jugada[i];
    }
    //borra la jugada
    delete[] jugada;
}

bool serieValida(const tJugada& jugada, const int numfichas) {

    int contadorSerie = 0;
    bool validez = true;

    //mientras sea mismo numero y distinto color
    //tambien podriamos haber usado la misma funcion que usamos en ponerficha pero si aprovechamos este while es mas eficiente
    while (jugada[contadorSerie]->num == jugada[contadorSerie + 1]->num and jugada[contadorSerie]->color != jugada[contadorSerie + 1]->color and jugada[contadorSerie]->color != jugada[contadorSerie + 2]->color) {

        contadorSerie++;
    }

    //chuequea que no pase el maximo de fichas por serie, al igual que chequea q el ultimo y el primero sean de distinto color
    if (contadorSerie > 4 or jugada[contadorSerie]->color == jugada[0]->color) {

        validez = false;
    }

    //si la jugada no es valida devuelve un -1
    if ( contadorSerie != numfichas - 1) {

        validez = false;
    }

    return validez;
}

bool escaleraValida(const tJugada& jugada, const int numfichas) {

    int  contadorEscalera = 0, restaPrevia;
    bool validez=true;

    //esto permite q una escalera sea creciente o decreciente
    restaPrevia = jugada[0]->num - jugada[1]->num;

    //mientras compartan la misma diferencia entre todas fichas contiguas y sean el mismo color
    while (jugada[contadorEscalera]->color == jugada[contadorEscalera + 1]->color and restaPrevia == jugada[contadorEscalera]->num - jugada[contadorEscalera + 1]->num and jugada[contadorEscalera]->num != jugada[contadorEscalera + 1]->num) {

        restaPrevia = jugada[contadorEscalera]->num - jugada[contadorEscalera + 1]->num;
        contadorEscalera++;
    }

    //si la jugada no es valida devuelve un -1
    if (contadorEscalera != numfichas - 1) {

        validez = false;
    }
    return validez;
}

