/*
	Nodo multi enlace (4 enlaces)

*/

#pragma once

#include <iostream>
#include <sstream>

using namespace std;

static const int NORTE = 0;
static const int ESTE = 1;
static const int SUR = 2;
static const int OESTE = 3;

class NodoMulti {
private:
	static int cantidadNodosMulti;

	int dato;
	NodoMulti *enlaceNorte;
	NodoMulti *enlaceEste;
	NodoMulti *enlaceSur;
	NodoMulti *enlaceOeste;
public:
	NodoMulti();
	~NodoMulti();

	// template <class T> const
	int getDato();

	NodoMulti* getEnlaceNorte();
	void setEnlaceNorte(NodoMulti*);

	NodoMulti* getEnlaceEste();
	void setEnlaceEste(NodoMulti*);

	NodoMulti* getEnlaceSur();
	void setEnlaceSur(NodoMulti*);

	NodoMulti* getEnlaceOeste();
	void setEnlaceOeste(NodoMulti*);

	static int getCantidadNodos();

	string toString();
};

