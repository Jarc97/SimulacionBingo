
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

static const int NORTE = 0;
static const int ESTE = 1;
static const int SUR = 2;
static const int OESTE = 3;

class nodoMulti {
private:
	static int cantidadNodosMulti;

	int dato;
	nodoMulti *enlaceNorte;
	nodoMulti *enlaceEste;
	nodoMulti *enlaceSur;
	nodoMulti *enlaceOeste;
public:
	nodoMulti();
	~nodoMulti();

	// template <class T> const
	int getDato();

	nodoMulti* getEnlaceNorte();
	void setEnlaceNorte(nodoMulti*);

	nodoMulti* getEnlaceEste();
	void setEnlaceEste(nodoMulti*);

	nodoMulti* getEnlaceSur();
	void setEnlaceSur(nodoMulti*);

	nodoMulti* getEnlaceOeste();
	void setEnlaceOeste(nodoMulti*);

	static int getCantidadNodos();

	string toString();
};
