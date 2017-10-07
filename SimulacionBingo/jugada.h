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
public:
	jugada(int cantJ, int cantC, int tipoJ);
	~jugada();
};

