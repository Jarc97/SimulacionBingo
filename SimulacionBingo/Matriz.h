#pragma once

#include "NodoMulti.h";

class Matriz {
private:
	NodoMulti *origen;
public:
	Matriz(int columnas, int filas);
	~Matriz();

	string toString();
};

