#pragma once
#include <iostream>
#include <sstream>
#include "matriz.h"
using namespace std;
class jugador{

private:
	int numeroJugador;
	int cantCartones;
	matriz **cartones;
public:
	void setNumero(int n);
	matriz** getCartones();

	int getNumero();
	string toString();
	jugador(int n,int can);
	jugador();
	~jugador();
};

