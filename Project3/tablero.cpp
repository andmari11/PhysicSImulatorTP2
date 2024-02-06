#include "tablero.h"


void mostrar(const tTablero& tablero) {


    cout << "Tablero:" << endl;
    for (int i = 0; i < tablero.contador; i++) {

        cout << setw(2) << i + 1 << ":";
        mostrar(tablero.jugadas[i]);
        cout << endl;

    }
    cout << endl;
}

bool jugar(tTablero& tablero, tSoporte& soporte) {

    tJugada jugada;
    int numfichas = 0, fichaSoporte;
    bool exito = true;

    iniJugada(jugada);
    mostrar(soporte);

    //se numeran las fichas para hacer mas facil su eleccion 
    //juez no encaja recordatorio setw(4)
    cout << "            ";
    for (int i = 1; i <= soporte.contador; i++) {

        cout << i << setw(5);
    }

    cout << endl << endl << "    Fichas (0 al final): ";
    cin >> fichaSoporte;

    //el jugador introduce las fichas que va a colocar
    while (fichaSoporte != 0) {

        jugada[numfichas]->num = soporte.array[fichaSoporte - 1]->num;
        jugada[numfichas]->color = soporte.array[fichaSoporte - 1]->color;

        numfichas++;
        cin >> fichaSoporte;
    }

    cout << endl << "Jugada:";
    mostrar(jugada);

    //la jugada a introducir es mayor q uno 
    if (numfichas != 1) {

        //nuevajugada devuelve un numero mayor q 3 si es valida la jugada y -1 si no lo es
        numfichas = nuevaJugada(soporte, jugada);

        //ha devuelto un numero mayor q dos por lo q es valido
        if (numfichas > 2) {

            //se actualiza las fichas del soporte
            eliminaFichas(soporte, jugada);

            //el puntero jugada del tablero apunta a la jugada valida
            tablero.jugadas[tablero.contador] = jugada;
            tablero.contador++;

            mostrar(tablero);
            exito = true;
        }

        else {

            exito = false;
        }
    }
    //no se trata de una jugada nueva sino de colocar una ficha
    else {

        int filaTablero = 0;
        exito = false;

        //intenta colocar la ficha en cada jugada del tablero hasta q lo consiga o llegue al final
        while (!exito and tablero.contador > filaTablero) {

            exito = ponerFicha(tablero.jugadas[filaTablero], jugada[0]);
            if (!exito) {

                filaTablero++;
            }
        }

        //consigue colocarla
        if (exito) {

            eliminaFichas(soporte, jugada);
            delJugada(jugada);

            cout << endl << "Jugadas del tablero donde poner la ficha: " << filaTablero + 1;
            cout << "  -> Colocada!" << endl << endl;

            mostrar(tablero);
        }
    }

    //no lo consigue
    if (!exito) {
        delJugada(jugada);
        cout << "  - No es una jugada correcta! Prueba de nuevo... ";
    }

    mostrar(soporte);
    return exito;
}

void delTablero(tTablero& tablero) {

    //borra cada jugada del tablero
    for (int i = 0; i < tablero.contador; i++) {

        delJugada(tablero.jugadas[i]);
    }

    //borra el tablero
    delete[] tablero.jugadas;
}