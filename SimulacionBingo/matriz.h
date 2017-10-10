#pragma once

#include "nodoMulti.h";

class matriz {
private:
	nodoMulti *origen;
public:
	matriz(int columnas, int filas);
	~matriz();

	string toString();
};

