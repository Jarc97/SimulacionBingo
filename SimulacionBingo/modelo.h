#pragma once
#include "jugada.h"
#include "vista.h"
#include "Pila.h"
#include "Matriz.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class modelo
{ 
	Pila <int>* pilaNumeros;
	jugada* simula;
	bool bingo;
	jugador* Jganador;
	Matriz* cartonGanador;
public:
	void iniciarJugada();
	void verJugadas();
	int serJugador();
	bool ganador();
	void iniciarSimulacion();
	void procesoInicio();
	void procesoMenuPrincipal();
	modelo();
	~modelo();
};

