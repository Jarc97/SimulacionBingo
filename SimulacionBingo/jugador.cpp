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

Matriz* jugador:: obtenerCarton(int op) {
	return cartones[op];
}
void jugador::setTipoJ(int c) {
	for (int i = 0; i < cantCartones; i++) {
		cartones[i]->setTipoJuego(c);

	}
}
bool jugador::existeGanador() {
	bool op = false;
	for (int i = 0; i < cantCartones; i++) {
		if (cartones[i]->GetJuegoCompletado() == true) {
			op = true;
		}
	}
		return op;
}
jugador::jugador() {}

jugador::~jugador()
{
}

void jugador::buscar(int num) {
	for (int i = 0; i < cantCartones;i++) {
		cartones[i]->busqueda(num);
	}
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
int jugador::getCantCartones() {
	return cantCartones;
}
string jugador::toString() {
	stringstream s;
	s << cantCartones << " cartones " << endl;
	for (int i = 0; i < cantCartones;i++) {
		s << cartones[i]->toString() << endl;
	}
	return s.str();
}
