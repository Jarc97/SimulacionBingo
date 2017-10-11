#include "jugador.h"



jugador::jugador(int n, int can)
{
	numeroJugador = n;
	cantCartones = can;

	cartones = new Matriz*[can];

	for (int i = 0; i < can; i++) {
		cartones[i] = new Matriz(5,5);
		cartones[i]->llenar();
	
	}

}
void jugador::buscar(int num) {
	for (int i = 0; i < cantCartones; i++) {
		cartones[i]->busqueda(num);
	}
}
void jugador::setTipoJ(int c) {
	for (int i = 0; i < cantCartones; i++) {
		cartones[i]->setTipoJuego(c);

	}
}
bool jugador::esGanador() {
	bool op = false;
	for (int i = 0; i < cantCartones; i++) {
		if (cartones[i]->getCompleto()==true) {
			op = true;
		}
		op = false;
	}
	return op;
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
	s << cantCartones << " cartones " << endl;
	for (int i = 0; i < cantCartones;i++) {
		s << cartones[i]->toString() << endl;
	}
	return s.str();
}
