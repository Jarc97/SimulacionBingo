#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class jugador{

private:
	int numeroJugador;
	int cantCartones;

public:
	void setNumero(int n);
	int getNumero();
	string toString();
	jugador(int n,int can);
	jugador();
	~jugador();
};

