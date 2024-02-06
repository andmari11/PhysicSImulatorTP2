#include "soporte.h"

void mostrar(const tSoporte& soporte) {

    cout << endl;
    cout << "Soporte:";

    for (int i = 0; i < soporte.contador; i++) {
        
        //muestra la jugada del soporte
        mostrar(soporte.array[i]);
    }

    cout << endl;
}

void ordenarPorNum(tSoporte& soporte) {

    int pos;
    tFicha* elemento;

    for (int i = 1; i < soporte.contador; i++) {

        elemento = soporte.array[i];
        pos = 0;

        //mayor numero o mismo numero pero mayor color
        while (pos < i and (soporte.array[pos]->num < elemento->num or (soporte.array[pos]->num == elemento->num and soporte.array[pos]->color < elemento->color))) {

            pos++;
        }

        //recoloca el array
        for (int j = i; j > pos; j--) {

            soporte.array[j] = soporte.array[j - 1];
        }

        soporte.array[pos] = elemento;
    }
    elemento = NULL;
    delete elemento;
}

void ordenarPorColor(tSoporte& soporte) {

    int pos;
    tFicha* elemento;

    for (int i = 1; i < soporte.contador; i++) {

        elemento = soporte.array[i];
        pos = 0;

        //en caso de que sea mayor el color o igual color y mayor numero compararColor sera true
        while (pos < i and (soporte.array[pos]->color < elemento->color or (soporte.array[pos]->color == elemento->color and soporte.array[pos]->num < elemento->num))) {

            pos++;
        }

        //recoloca el array para colocar elemento
        for (int j = i; j > pos; j--) {

            soporte.array[j] = soporte.array[j - 1];
        }

        soporte.array[pos] = elemento;
    }
    elemento = NULL;
    delete elemento;
}

void mostrarSeries(tSoporte& soporte) {

    tJugada jugada;
    int contadorJugada = 1;

    ordenarPorNum(soporte);
    iniJugada(jugada);

    //se añade la primera ficha a la jugada
    jugada[0]->color = soporte.array[0]->color;
    jugada[0]->num = soporte.array[0]->num;


    for (int i = 1; i < soporte.contador; i++) {

        //si el soporte tiene la misma ficha repetida la salta para evitar confusion 
        //y al haber solo dos fichas con el mismo numero y mismo color evitamos mostrar series con colores repetidos

        if (i != soporte.contador - 1 and jugada[contadorJugada - 1]->color == soporte.array[i]->color and jugada[contadorJugada - 1]->num == soporte.array[i]->num) {

            i++;
        }

        //la ficha tiene el mismo numero asi q lo añado a la jugada
        if (soporte.array[i]->num == jugada[contadorJugada - 1]->num) {

            jugada[contadorJugada]->num = soporte.array[i]->num;
            jugada[contadorJugada]->color = soporte.array[i]->color;

            contadorJugada++;
        }

        //la siguiente ficha es distinta o hemos llegado al final del soporte
        if (soporte.array[i]->num != jugada[contadorJugada - 1]->num or i + 1 == soporte.contador) {

            //si tiene mas de 3 fichas es valida
            if (contadorJugada >= 3) {
                cout << endl;
                mostrar(jugada);
            }

            //reseteamos de todas formas
            resetJugada(jugada);
            contadorJugada = 1;
            jugada[0]->num = soporte.array[i]->num;
            jugada[0]->color = soporte.array[i]->color;
        }
    }

    delJugada(jugada);
}

void mostrarEscaleras(tSoporte& soporte) {

    tJugada jugada;
    int contadorJugada = 0;
    bool escalera = true;

    iniJugada(jugada);
    ordenarPorColor(soporte);

    //añade la primera ficha del soporte a la jugada
    contadorJugada = 1;
    jugada[0]->color = soporte.array[0]->color;
    jugada[0]->num = soporte.array[0]->num;

    for (int i = 1; i < soporte.contador; i++) {

        //salta la siguiente ficha si esta repetida para evitar confusion (si esta en lam ultima posicion no lo chequea)
        if (i != soporte.contador - 1 and soporte.array[i + 1] == soporte.array[i]) {

            i++;
        }

        //la siguiente ficha es del mismo color y un numero mayor por lo que se le añade a la jugada
        if (soporte.array[i]->num == jugada[contadorJugada - 1]->num + 1 and soporte.array[i]->color == jugada[contadorJugada - 1]->color) {

            jugada[contadorJugada]->color = soporte.array[i]->color;
            jugada[contadorJugada]->num = soporte.array[i]->num;
            contadorJugada++;
        }
        //la siguiente ficha no lo cumple asi que se corta la escalera
        else {

            escalera = false;
        }


        //la siguiente ficha no forma parte de la escalera o se ha llegado al final del soporte
        if (!escalera or i == soporte.contador - 1) {

            //es una escalera valida por lo que se muestra
            if (contadorJugada >= 3) {
                cout << endl;
                mostrar(jugada);
            }

            //se resetea la jugada y se añade la siguiente ficha a la jugada
            resetJugada(jugada);
            contadorJugada = 1;
            jugada[0]->color = soporte.array[i]->color;
            jugada[0]->num = soporte.array[i]->num;
        }

        //se intenta una escalera de nuevo
        escalera = true;
    }

    //elimina la jugada
    delJugada(jugada);

}

void sugerir(tSoporte& soporte) {

    mostrarSeries(soporte);
    mostrarEscaleras(soporte);
    mostrar(soporte);
}

void eliminaFichas(tSoporte& soporte, tJugada& jugada) {

    for (int i = 0; i < soporte.contador; i++) {

        //en caso de que en el soporte haya fichas repetidas, para que no se borren las dos
        if (i + 1 < soporte.contador and (soporte.array[i]->color == soporte.array[i + 1]->color and soporte.array[i]->num == soporte.array[i + 1]->num)) {

            i++;
        }

        //no esta en la jugada
        if (buscar(jugada, soporte.array[i]) != -1) {

            soporte.array[i]->num = -1;
        }

    }

    //se recoloca el soporte
    for (int i = 0; i < soporte.contador; i++) {

        //se llena el espacio vacio
        if (soporte.array[i]->num == -1) {

            soporte.contador--;

            for (int j = i; j < soporte.contador; j++) {

                soporte.array[j]->color = soporte.array[j + 1]->color;
                soporte.array[j]->num = soporte.array[j + 1]->num;

            }

            i--;
        }
    }

    //en caso de que hayan mas de 8 posiciones libres se empequeñecera el tamaño del soporte
    while (soporte.capacidad - soporte.contador >= 8 and soporte.contador != 0) {
        
        //se crea un soporte auxiliar con -8 de cpacidad
        soporte.capacidad=soporte.capacidad-8;
        tFicha** aux= new tFicha*[soporte.capacidad];

        //se copia el contenido del soporte al auxiliar
        for(int i=0; i<soporte.capacidad + 8;i++){

            if (i < soporte.capacidad) {
                aux[i] = new tFicha;

                if (i < soporte.contador) {

                    aux[i]->color = soporte.array[i]->color;
                    aux[i]->num = soporte.array[i]->num;

                }
            }
            //se elimina el soporte viejo
            delete soporte.array[i];
        }

        delete[] soporte.array;

        //el puntero apunta ahora al soporte auxiliar
        soporte.array=aux;
    }
}

void nuevaFicha(tFicha* ficha, tSoporte& soporte) {

    //en caso de que el soporte haya llegado a su capacidad max
    if (soporte.capacidad <= soporte.contador) {

        //crea un soporte auxiliar con +8 de capacidad
        tFicha** aux = new tFicha * [soporte.capacidad + 8];

        for (int i = 0; i < soporte.capacidad + 8; i++) {

            aux[i] = new tFicha;

            //copia las fichas del soporte al soporte auxiliar
            if (i < soporte.contador) {

                aux[i]->color = soporte.array[i]->color;
                aux[i]->num = soporte.array[i]->num;
            }

            //elimina el soporte antiguo
            if (i < soporte.capacidad) {

                delete[] soporte.array[i];
            }
        }

        delete[] soporte.array;

        //soporte apunta al soporte nuevo y actualiza la capacidad
        soporte.array = aux;
        soporte.capacidad = soporte.capacidad + 8;
    }

    //se anade la ficha al soporte
    soporte.array[soporte.contador]->color = ficha->color;
    soporte.array[soporte.contador]->num = ficha->num;

    //se marca que se ha a�adido una ficha mas al soporte
    soporte.contador++;
    delete ficha;
}

int nuevaJugada(tSoporte& soporte, tJugada& jugada) {

    int numfichas = 0;

    //cuenta cuantas fichas hay en la jugada
    while (jugada[numfichas]->num != -1) {

        numfichas++;
    }

    //el minimo de fichas tiene que ser 3 para q sea jugada valida, en caso 
    if (numfichas >= 3) {

        //chequea q sea valida la serie
        if (serieValida(jugada, numfichas)) {

            cout << "   - Serie correcta!" << endl << endl;

        }
        //chequea que sea valida la escalera
        else if (escaleraValida(jugada, numfichas)) {

            cout << "   - Escalera correcta!" << endl << endl;
        }
        else {

            numfichas = -1;   
        }
    }

    return numfichas;
}