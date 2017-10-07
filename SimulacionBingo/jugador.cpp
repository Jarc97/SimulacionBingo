#include "jugador.h"



jugador::jugador(int n, int can)
{
	numeroJugador = n;
	cantCartones = can;
}
jugador::jugador() {}

jugador::~jugador()
{
}

void jugador::setNumero(int n){
	numeroJugador = n;
}

int jugador::getNumero() {
	return numeroJugador;
}
string jugador::toString() {
	stringstream s;
	s << "Jugador Numero :" << numeroJugador << endl;
	return s.str();
}
