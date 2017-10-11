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
	void buscar(int num);
	bool esGanador();
	void setNumero(int n);
	Matriz** getCartones();
	void setTipoJ(int );
	int getNumero();
	string toString();
	jugador(int n,int can);
	jugador();
	~jugador();
};

