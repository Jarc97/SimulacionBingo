
#include "matriz.h"

matriz::matriz(int columnas, int filas) {
	// Auxiliares
	nodoMulti *ultimoCreado = nullptr;
	nodoMulti *nodoArriba = nullptr;

	// for especial para la primer fila de nodos
	for (int i = 0; i < columnas; i++) {
		// Es el primer nodo que se va a crear?
		if (i == 0) {
			origen = new nodoMulti();
			ultimoCreado = origen;
		}
		else {
			nodoMulti *nuevo = new nodoMulti();		// Crear nuevo nodo
			nuevo->setEnlaceOeste(ultimoCreado);	// enlazar el nuevo al anterior
			ultimoCreado->setEnlaceEste(nuevo);		// enlazar el anterior al nuevo
			ultimoCreado = nuevo;					// cambiar el ultimoCreado al nuevo
		}
	}
	nodoArriba = origen;						// Recordar primer nodo de ultima fila (arriba)

												// for para el resto de la matriz
	for (int i = 0; i < filas - 1; i++) {
		for (int j = 0; j < columnas; j++) {
			// Es el primer nodo de la fila?
			if (j == 0) {
				nodoMulti *nuevoPrimero = new nodoMulti();
				nuevoPrimero->setEnlaceNorte(nodoArriba);	// enlazar norte
				nodoArriba->setEnlaceSur(nuevoPrimero);
				nodoArriba = nodoArriba->getEnlaceEste();	// actualizar el nodoArriba hacia el Este
				ultimoCreado = nuevoPrimero;
			}
			else {
				nodoMulti *nuevo = new nodoMulti();

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


matriz::~matriz() {
}

string matriz::toString() {
	stringstream ss;
	ss <<"origen "<< origen->toString() << endl << endl;
	ss <<"Este "<< origen->getEnlaceEste()->toString() << endl << endl;
	ss <<"Sur "<< origen->getEnlaceSur()->toString() << endl << endl;
	ss <<"Sur Este "<< origen->getEnlaceSur()->getEnlaceEste()->toString() << endl << endl;
	return ss.str();
}
