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
	string toString();
	void buscar(int num);
	jugada(int cantJ, int cantC, int tipoJ);
	jugador* getGanador();
	bool hayGanador();
	void setGanador(jugador*);
	~jugada();
};

