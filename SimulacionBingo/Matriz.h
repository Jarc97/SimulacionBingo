#pragma once

#include "NodoMulti.h";

class Numero;

class Matriz {
private:
	NodoMulti *origen;
public:
	Matriz();
	Matriz(int columnas, int filas);
	~Matriz();
	int get(int x, int y);

	NodoMulti* operator[](int x);
	

	string toString();
};

