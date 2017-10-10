#include "jugador.h"



jugador::jugador(int n, int can)
{
	numeroJugador = n;
	cantCartones = can;

	/*cartones = new matriz*[can];

	for (int i = 0; i < can; i++) {
		cartones[i] = new matriz(2,2);
	}
*/
}
jugador::jugador() {}

jugador::~jugador()
{
}
//matriz** jugador:: getCartones() {
//	return cartones;
//}

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
