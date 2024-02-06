#pragma once

#ifndef soporte.h

    #include "soporte.h"
#endif 

#ifndef bolsa.h

    #include "bolsa.h"

#endif 


struct tSoportes {

    int contadorJugadores = 0;
    tSoporte* soporte;
};

//reparte fichas aleatorias a los jugadores
void repartir(tBolsa& bolsa, tSoportes& soportes);

//inicializa los soportes
void iniSoporte(tSoportes& soportes);

//elimina los soportes
void delSoportes(tSoportes& soportes);

