#pragma once
#include <iostream>
#include <sstream>
#include "jugador.h"

using namespace std;
class jugada
{
private:

	int cantJugadores;
	int cantCartonesMax;
	int tipoJuego;
	jugador **vectorJugadores;
	jugador* ganador;
public:
	bool hayGanador();
	jugador** obtenerJugadores();
	string toString();
	void setTipoCarton(int tipoJ);
	void buscar(int num);
	jugador* obtenerJugador(int p);
	int obtenerCantJugadores();
	jugada(int cantJ, int cantC, int tipoJ);
	jugador* getGanador();
	void setGanador(jugador*);
	Matriz* cartonGanador(Matriz* op);
	~jugada();
};

