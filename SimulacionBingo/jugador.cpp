#include "jugador.h"



jugador::jugador(int n, int can)
{
	numeroJugador = n;
	cantCartones = can;

	cartones = new Matriz*[can];

	for (int i = 0; i < can; i++) {
		cartones[i] = new Matriz(5,5);
	}

}
jugador::jugador() {}

jugador::~jugador()
{
}
Matriz** jugador:: getCartones() {
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
	s << " Jugador Numero :" << numeroJugador << endl;

	return s.str();
}
