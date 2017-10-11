#include "Matriz.h"
#include "Numero.h"

Matriz::Matriz() {
	origen = nullptr;
}

Matriz::Matriz(int columnas, int filas) {
	if (columnas <= 0 || filas <= 0) {
		return;
	}
	// Auxiliares
	NodoMulti *ultimoCreado = nullptr;			// recordar el ultimo nodo creado
	NodoMulti *nodoInicialArriba = nullptr;		// recordar el primer nodo de cada fila
	NodoMulti *nodoArriba = nullptr;			// puntero que se mueve a la derecha (arriba) cada vez que aparece un nodo nuevo

	// for especial para la primer fila de nodos
	for (int i = 0; i < columnas; i++) {
		// Es el primer nodo que se va a crear?
		if (i == 0) {
			origen = new NodoMulti();
			ultimoCreado = origen;
		}
		else {
			NodoMulti *nuevo = new NodoMulti();
			nuevo->setEnlaceOeste(ultimoCreado);	// enlazar el nuevo al anterior
			ultimoCreado->setEnlaceEste(nuevo);		// enlazar el anterior al nuevo
			ultimoCreado = nuevo;					// actualizar el ultimoCreado
		}
	}
	nodoInicialArriba = nodoArriba = origen;		// Recordar primer nodo de la primer fila

	// for para el resto de la matriz (filas-1: ya se creó una fila)
 	for (int i = 0; i < filas-1; i++) {
		for (int j = 0; j < columnas; j++) {
			// Es el primer nodo de la fila?
			if (j == 0) {
				NodoMulti *nuevoPrimero = new NodoMulti();
				nuevoPrimero->setEnlaceNorte(nodoInicialArriba);	// enlazar el Norte
				nodoInicialArriba->setEnlaceSur(nuevoPrimero);
				nodoArriba = nodoArriba->getEnlaceEste();			// actualizar el nodoArriba hacia el Este
				ultimoCreado = nuevoPrimero;
				nodoInicialArriba = nuevoPrimero;		// nuevoPrimero será el nodoInicialArriba para la siguiente fila
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
		// Al finalizar la fila, nodoArriba inicia igual que nodoInicialArriba
		nodoArriba = nodoInicialArriba;
	}
}


Matriz::~Matriz() {
}

bool Matriz::operator()(int columna, int fila, int num) {
	NodoMulti *actual = origen;
	// Iterar sobre las columnas (Este)
	for (int i = 0; i < columna; i++) {
		if (actual->getEnlaceEste() != nullptr) {
			actual = actual->getEnlaceEste();
		}
		else {
			return false;		// fuera de limite
		}
	}

	// Iterar sobre las filas (Sur)
	for (int j = 0; j < fila; j++) {
		if (actual->getEnlaceSur() != nullptr) {
			actual = actual->getEnlaceSur();
		}
		else {
			return false;		// fuera de limite
		}
	}

	// modificar el dato
	actual->getDato()->setValor(num);
}

Numero* Matriz::operator()(int columna, int fila) {
	NodoMulti *actual = origen;
	// Iterar sobre las columnas (Este)
	for (int i = 0; i < columna; i++) {
		if (actual->getEnlaceEste() != nullptr) {
			actual = actual->getEnlaceEste();
		}
		else {
			return nullptr;		// fuera de limite
		}
	}

	// Iterar sobre las filas (Sur)
	for (int j = 0; j < fila; j++) {
		if (actual->getEnlaceSur() != nullptr) {
			actual = actual->getEnlaceSur();
		}
		else {
			return nullptr;		// fuera de limite
		}
	}
	
	if (actual) {
		return actual->getDato();
	}
	return nullptr;
}

string Matriz::toString() {
	int x, y = 0;
	stringstream ss;
	
	return ss.str();
}