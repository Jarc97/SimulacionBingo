#include "jugador.h"



jugador::jugador(int n, int can)
{
	numeroJugador = n;
	cantCartones = can;

	cartones = new matriz*[can];

	for (int i = 0; i < can; i++) {
		cartones[i] = new matriz(5,5);
	}

}
jugador::jugador() {}

jugador::~jugador()
{
}
matriz** jugador:: getCartones() {
	return cartones;
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

	for (int i = 0; i < cantCartones; i++) {
		s<< cartones[i]->toString() << endl;;
	}
	return s.str();
}
