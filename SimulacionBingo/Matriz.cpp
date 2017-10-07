#include "Matriz.h"

Matriz::Matriz(int columnas, int filas) {
	// Auxiliares
	NodoMulti *ultimoCreado = nullptr;
	NodoMulti *nodoArriba = nullptr;

	// for especial para la primer fila de nodos
	for (int i = 0; i < columnas; i++) {
		// Es el primer nodo que se va a crear?
		if (i == 0) {
			origen = new NodoMulti();
			ultimoCreado = origen;
		}
		else {
			NodoMulti *nuevo = new NodoMulti();		// Crear nuevo nodo
			nuevo->setEnlaceOeste(ultimoCreado);	// enlazar el nuevo al anterior
			ultimoCreado->setEnlaceEste(nuevo);		// enlazar el anterior al nuevo
			ultimoCreado = nuevo;					// cambiar el ultimoCreado al nuevo
		}
	}
	nodoArriba = origen;						// Recordar primer nodo de ultima fila (arriba)

	// for para el resto de la matriz
 	for (int i = 0; i < filas-1; i++) {
		for (int j = 0; j < columnas; j++) {
			// Es el primer nodo de la fila?
			if (j == 0) {
				NodoMulti *nuevoPrimero = new NodoMulti();
				nuevoPrimero->setEnlaceNorte(nodoArriba);	// enlazar norte
				nodoArriba->setEnlaceSur(nuevoPrimero);
				nodoArriba = nodoArriba->getEnlaceEste();	// actualizar el nodoArriba hacia el Este
				ultimoCreado = nuevoPrimero;
			}
			else {
				NodoMulti *nuevo = new NodoMulti();

				nuevo->setEnlaceOeste(ultimoCreado);
				ultimoCreado->setEnlaceEste(nuevo);

				nuevo->setEnlaceNorte(nodoArriba);
				nodoArriba->setEnlaceSur(nuevo);
				nodoArriba = nodoArriba->getEnlaceEste();

				ultimoCreado = nuevo;
			}
		}
	}
}


Matriz::~Matriz() {
}

string Matriz::toString() {
	stringstream ss;
	ss << origen->toString() << endl << endl;
	ss << origen->getEnlaceEste()->toString() << endl << endl;
	ss << origen->getEnlaceSur()->toString() << endl << endl;
	ss << origen->getEnlaceSur()->getEnlaceEste()->toString() << endl << endl;
	return ss.str();
}