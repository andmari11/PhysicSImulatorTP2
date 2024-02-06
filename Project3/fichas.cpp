#include "fichas.h"

void mostrar(tFicha* ficha) {

    //la ficha existe(recordatorio hemos añadido un espacio mas)
    if (ficha != NULL and ficha->num != -1) {

        //muestra el numero con el color correspondiente
        colorTexto(ficha->color);
        cout << setw(5) << ficha->num;
    }

    //la ficha esta libre por lo que se muestra el espacio vacio
    else {

        cout << "     ";
    }

    //vuelve a poner blanco el texto
    cout << "\033[40;37m";

}

