#include "soportes.h"

const int MAX_JUGADORES = 4;
const int MIN_JUGADORES = 2;

const int MAX_NUM_FICHAS = 13;
const int MIN_NUM_FICHAS = 8;

const int MAX_INI_FICHAS = 14;
const int MIN_INI_FICHAS = 6;

void repartir(tBolsa& bolsa, tSoportes& soportes) {
    int ini_fichas;

    iniSoporte(soportes);

    cout << "Introduzca el numero de fichas por jugador: ";
    cin >> ini_fichas;


    while (ini_fichas > MAX_INI_FICHAS or ini_fichas < MIN_INI_FICHAS) {

        cout << "Número no válido, debe ser un numero entre " << MIN_INI_FICHAS << " y " << MAX_INI_FICHAS << endl << "Introduzca el numero de fichas por jugador: ";
        cin >> ini_fichas;

    }

    cout << endl << "Fichas de la bolsa con todas las fichas repartidas" << endl << endl;

    //se reparten a num_jugadores jugadores
    for (int i = 0; i < soportes.contadorJugadores; i++) {

        //se reparten ini_fichas a cada jugador
        for (int j = 0; j < ini_fichas; j++) {

            nuevaFicha(robar(bolsa), soportes.soporte[i]);
            //pasa la ficha de la bolsa al ultimo hueco del soporte del jugador
            //mostrar(soportes.soporte[i]);

        }

        mostrar(soportes.soporte[i]);
    }

    mostrar(bolsa);

}

void delSoportes(tSoportes& soportes) {

    for (int i = 0; i < soportes.contadorJugadores; i++) {


        for (int j = 0; j < soportes.soporte[i].capacidad; j++) {


            delete soportes.soporte[i].array[j];

        }

        delete soportes.soporte[i].array;
    }

    delete soportes.soporte;
}

void iniSoporte(tSoportes& soportes) {

    cout << "Introduzca el numero de jugadores:";
    cin>> soportes.contadorJugadores;


    while (soportes.contadorJugadores > MAX_JUGADORES or soportes.contadorJugadores < MIN_JUGADORES) {

        cout << "Número no válido, debe ser un numero entre " << MIN_JUGADORES << " y " << MAX_JUGADORES << endl << "Introduzca el numero de jugadores:";
        cin >> soportes.contadorJugadores;

    }

    soportes.soporte = new tSoporte[soportes.contadorJugadores];

    for (int i = 0; i < soportes.contadorJugadores; i++) {

        soportes.soporte[i].array = new tFicha * [8];

        for (int j = 0; j < soportes.soporte[i].capacidad; j++) {

            soportes.soporte[i].array[j] = new tFicha;
        }
    }
}
