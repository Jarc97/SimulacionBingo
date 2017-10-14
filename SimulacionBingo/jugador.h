#pragma once
#include <iostream>
#include <sstream>
#include "Matriz.h"
#include "TableroBingo.h"
using namespace std;
class jugador{

private:
	int numeroJugador;
	int cantCartones;
   Matriz **cartones;
public:
	bool existeGanador();
	void setNumero(int n);
	Matriz** getCartones();
	int getCantCartones();
	void setTipoJ(int );
	Matriz* obtenerCarton(int op);
	int getNumero();
	void buscar(int num);
	string toString();
	jugador(int n,int can);
	jugador();
	~jugador();
};

