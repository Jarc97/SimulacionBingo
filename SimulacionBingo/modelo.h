#pragma once
#include "jugada.h"
#include "vista.h"
#include "Pila.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class modelo
{
	Pila <int> pilaNumeros;
	jugada* simula;
	bool bingo;
public:
	bool existeGanador();
	void iniciarJugada();
	void verJugadas();
	void iniciarSimulacion();
	void procesoInicio();
	int tipoJuego();
	void procesoMenuPrincipal();
	modelo();
	~modelo();
};

