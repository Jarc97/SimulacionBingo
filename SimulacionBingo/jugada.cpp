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
		vectorJugadores[i]->setTipoJ(tipoJuego);
		}
}
void jugada::setTipoCarton(int tipoJ) {
	for (int i = 0; i < cantJugadores; i++) {
		vectorJugadores[i]->setTipoJ(tipoJ);
	}
}
void jugada::buscar(int num) {
	
	for (int i = 0; i < cantJugadores;i++) {
		vectorJugadores[i]->buscar(num);
	}
	
}
Matriz* jugada::cartonGanador(Matriz* op) {
	return op;
}
jugador* jugada::getGanador() {
	return ganador;
}
jugador** jugada::obtenerJugadores() {
	return vectorJugadores;
}
bool jugada::hayGanador() {
	bool op=false;
	for (int i = 0; i < cantJugadores; i++) {
		for (int k = 0; k < vectorJugadores[i]->getCantCartones(); k++) {
			if (vectorJugadores[i]->getCartones()[k]->GetJuegoCompletado() == true) {
				op = true;
				setGanador(vectorJugadores[i]);
			}
		}
		
	}
	return op;
}


jugador* jugada::obtenerJugador(int p) {
	return vectorJugadores[p];
}
int jugada::obtenerCantJugadores() {
	return cantJugadores;
}

void jugada::setGanador(jugador* j) {
	ganador = j;
}

string jugada::toString() {
	stringstream s;
	if (this->getGanador() != NULL) {
		s <<"Jugador ganador , Numero "<< ganador->getNumero()<<endl;
	}
	else {
		s << "sin ganador " << endl;
	}
	return s.str();
}
jugada::~jugada()
{
}
