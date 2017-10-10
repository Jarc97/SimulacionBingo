#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class jugador{

private:
	int numeroJugador;
	int cantCartones;
    // Matriz **cartones;
public:
	void setNumero(int n);
	//Matriz** getCartones();

	int getNumero();
	string toString();
	jugador(int n,int can);
	jugador();
	~jugador();
};

