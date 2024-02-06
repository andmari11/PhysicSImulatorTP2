#include "bolsa.h"

#ifndef const int NUM_FICHAS

const int NUM_FICHAS = 8;

#endif // !const int NUM_FICHAS


void inicializarBolsa(tBolsa& bolsa) {

    //se deja elegir al jugador los parametros del juego
    cout << "Introduzca el numero maximo de fichas: ";

    bolsa.fichas = new tFicha * *[8];

    bolsa.contador = 8 * NUM_FICHAS;

    for (int i = 0; i < 8; i++) {

        bolsa.fichas[i] = new tFicha * [NUM_FICHAS];

        for (int j = 0; j < NUM_FICHAS; j++) {

            bolsa.fichas[i][j] = new tFicha;

            //el color depende de la fila
            bolsa.fichas[i][j]->color = tColor(i % (4));

            //el numero depende de la columna
            bolsa.fichas[i][j]->num = j + 1;
        }
    }
}

void mostrar(const tBolsa& bolsa) {

    cout << "Bolsa..." << endl;
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < NUM_FICHAS; j++) {

            mostrar(bolsa.fichas[i][j]);
        }

        //se acaba la fila
        cout << endl;
    }
}

void delBolsa(tBolsa& bolsa) {

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < NUM_FICHAS; j++) {

            delete bolsa.fichas[i][j];
        }

        delete[] bolsa.fichas[i];
    }
    delete[] bolsa.fichas;
}

tFicha* robar(tBolsa& bolsa) {
    int fila, columna, filaINI = 0, columnaINI = 0;
    bool encontrada = false, final = false;
    tFicha* sol = NULL;


    filaINI = rand() % 8;
    columnaINI = rand() % NUM_FICHAS;

    //se guarda que ficha ha sido elegida al principio
    fila = filaINI;
    columna = columnaINI;

    //recorre la bolsa hasta q encuentre una ficha
    while (!encontrada and bolsa.contador != 0) {

        //se ha dado una vuelta por completo y no se ha encontrado una ficha
        if (fila == filaINI and columna == columnaINI and final) {

            encontrada = true;
        }

        //la ficha ya ha sido pillada
        else if (bolsa.fichas[fila][columna] == NULL) {

            //llega al final de la bolsa
            if (columna == NUM_FICHAS - 1 and fila == 7) {

                final = true;
                fila = 0;
                columna = 0;
            }
            //llega al final de una fila
            else if (columna == NUM_FICHAS - 1) {

                fila++;
                columna = 0;
            }
            //se desplaza a la siguiente ficha
            else {

                columna++;
            }
        }


        //la ficha esta disponible por lo q se acaba el bucle
        else {

            encontrada = true;
            sol = bolsa.fichas[fila][columna];

            bolsa.fichas[fila][columna] = NULL;
            delete bolsa.fichas[fila][columna];
            bolsa.contador--;
        }
    }

    return sol;
}