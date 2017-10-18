#pragma once

#include "jugada.h"
#include "vista.h"
#include "Pila.h"
#include "Matriz.h"

#include "boost_async_server.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include <Windows.h>


using namespace std;
class modelo
{ 
	Pila <int>* pilaNumeros;
	jugada* simula;
	bool bingo;
	jugador* Jganador;
	Matriz* cartonGanador;
	int ultimoNumero;

public:
	void iniciarJugada();
	void simulacion(int, int, int, bool&);
	void servidor(bool*, int*, int*, int*);
	int serJugador();
	bool ganador();
	void iniciarSimulacion();
	void procesoInicio();
	void procesoMenuPrincipal();
	modelo();
	~modelo();
};

