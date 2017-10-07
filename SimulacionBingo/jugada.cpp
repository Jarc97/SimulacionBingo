#include "jugada.h"



jugada::jugada(int cantJ, int cantC, int tipoJ)
{
	cantJugadores = cantJ;
	cantCartonesMax = cantC;
	tipoJuego = tipoJ;


	vectorJugadores = new jugador*[cantJ];

	for (int i = 0; i < cantJ; i++) {
		vectorJugadores[i] = new jugador(i+1, (1+(rand() % cantC)));
	}
}


jugada::~jugada()
{
}
