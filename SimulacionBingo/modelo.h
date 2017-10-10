#pragma once
#include "jugada.h"
#include "vista.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class modelo
{
	jugada* simula;
	bool bingo;
public:
	void iniciarJugada();
	void verJugadas();
	void iniciarSimulacion();
	void procesoInicio();
	int tipoJuego();
	void procesoMenuPrincipal();
	modelo();
	~modelo();
};

