#pragma once

#include "NodoMulti.h";

class Numero;

class Matriz {
private:
	NodoMulti *origen;
	int columnas, filas;
public:
	Matriz();
	Matriz(int columnas, int filas);
	~Matriz();

	// Sobrecarga para modificar elementos en la Matriz
	bool operator()(int columna, int fila, int num);

	// Sobrecarga para buscar elementos en la Matriz
	Numero* operator()(int columna, int fila);

	string toString();
};

