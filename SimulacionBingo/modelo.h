#pragma once
#include "jugada.h"
#include "vista.h"
using namespace std;
class modelo
{
	jugada* simula;
public:
	void iniciarJugada();
	void verJugadas();
	void procesoInicio();
	int tipoJuego();
	void procesoMenuPrincipal();
	modelo();
	~modelo();
};

