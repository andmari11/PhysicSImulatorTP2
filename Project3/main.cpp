//Andrés Marí Piqueras y Calixto Sánchez-Fresneda Redondo

#include "main.h"

int main() {

    srand(time(NULL));
    tBolsa bolsa;
    tSoportes soportes;
    tTablero tablero;
    tFicha* fichaRobada = NULL;
    bool fichaPuesta = false, bolsaVacia = false;

    tablero.jugadas = new tJugada[NUM_FICHAS * 2];

    inicializarBolsa(bolsa);
    mostrar(bolsa);
    repartir(bolsa, soportes);

    int turno = 1, opcion = 0;

    turno = rand() % (soportes.contadorJugadores - 1) + 1;

    //el juego acaba al recibir -1 como opcion
    while (opcion != -1) {

        cout << endl << "Turno para el jugador " << turno << " ...";

        mostrar(soportes.soporte[turno - 1]);
        opcion = menu();

        //si el jugador manda 0 su turno acaba
        while (opcion > 0) {

            switch (opcion) {
            case 1:
                ordenarPorNum(soportes.soporte[turno - 1]);
                mostrar(soportes.soporte[turno - 1]);
                break;
            case 2:
                ordenarPorColor(soportes.soporte[turno - 1]);
                mostrar(soportes.soporte[turno - 1]);
                break;
            case 3:
                sugerir(soportes.soporte[turno - 1]);
                break;
            case 4:
                //fichapuesta marca si se ha puesto una ficha correcta en algun momento del turno
                //esta puesta de manera para que si se intenta una jugada incorrecta tras jugar una correcta no fuerza al jugador a robar
                if (jugar(tablero, soportes.soporte[turno - 1])) {

                    fichaPuesta = true;
                }
                break;
            }

            //el jugador se ha quedado sin fichas
            if (soportes.soporte[turno - 1].contador == 0) {

                cout << endl << "El jugador " << turno << " ha ganado!";
                opcion = -1;
            }
            else {
                opcion = menu();
            }
        }

        //el jugador ha acabado su turno y no ha puesto una ficha
        if (opcion == 0 and !fichaPuesta and !bolsaVacia) {

            fichaRobada = robar(bolsa);

            //todavia queda al menos una ficha en la bolsa
            if (fichaRobada != NULL) {

                nuevaFicha(fichaRobada, soportes.soporte[turno - 1]);
                mostrar(soportes.soporte[turno - 1]);
            }

            //se marca que la bolsa esta vacia para que no tenga que recorrer la bolsa cada turno
            else {

                bolsaVacia = true;
            }

            fichaRobada = NULL;
        }

        //se pasa el turno al siguiente jugador
        turno = turno % soportes.contadorJugadores;
        turno++;
        fichaPuesta = false;
    }

    delete fichaRobada;
    delBolsa(bolsa);
    delSoportes(soportes);
    delTablero(tablero);

    _CrtDumpMemoryLeaks();

    return  0;
}


int menu() {

    int opcion;
    cout << endl << "1: Ordenar por num., 2: Ordenar por color, 3: Sugerir, 4: Poner, 0: Fin >>> ";
    cin >> opcion;

    //en caso de que se introduzca una opcion no valida
    while (opcion > 4 or opcion < -1) {

        cout << endl << "Valor introducido no correcto!";
        cout << endl << "1: Ordenar por num., 2: Ordenar por color, 3: Sugerir, 4: Poner, 0: Fin >>> ";
        cin >> opcion;
    }


    return opcion;
}








