#include "jugada.h"



jugada::jugada(int cantJ, int cantC, int tipoJ)
{
	cantJugadores = cantJ;
	cantCartonesMax = cantC;
	tipoJuego = tipoJ;
	ganador = NULL;

	vectorJugadores = new jugador*[cantJ];

	for (int i = 0; i < cantJ; i++) {
		vectorJugadores[i] = new jugador(i+1, (1+(rand() % cantC)));
		vectorJugadores[i]->setTipoJ(tipoJ);
		}
}
void jugada::buscar(int num) {
	for (int i = 0; i < cantJugadores; i++) {
		vectorJugadores[i]->buscar(num);
	}
}
jugador* jugada::getGanador() {
	return ganador;
}
bool jugada::hayGanador() {
	bool op = false;
	for (int i = 0; i < cantJugadores; i++) {
		if (vectorJugadores[i]->esGanador() == true) {
			op= true;
			setGanador(vectorJugadores[i]);
		}
		op= false;
	}
	return op;
}
void jugada::setGanador(jugador* j) {
	ganador = j;
}

string jugada::toString() {
	stringstream s;
	for (int i = 0; i < cantJugadores; i++) {
		s << vectorJugadores[i]->toString() << endl;
	}
	return s.str();
}
jugada::~jugada()
{
}
