
#include "nodoMulti.h"

// Inicializar variables static
int nodoMulti::cantidadNodosMulti = 0;

nodoMulti::nodoMulti() {
	cantidadNodosMulti++;

	int dato = 0;
	enlaceNorte = nullptr;
	enlaceEste = nullptr;
	enlaceSur = nullptr;
	enlaceOeste = nullptr;
	cout << this << endl;
}

nodoMulti::~nodoMulti() {
	// DESTRUCCION DE LOS ENLACES (WIP)
	cantidadNodosMulti--;
}

int nodoMulti::getDato() {
	return dato;
}


nodoMulti* nodoMulti::getEnlaceNorte() {
	return enlaceNorte;
}
void nodoMulti::setEnlaceNorte(nodoMulti *nodo) {
	enlaceNorte = nodo;
}


nodoMulti* nodoMulti::getEnlaceEste() {
	return enlaceEste;
}
void nodoMulti::setEnlaceEste(nodoMulti *nodo) {
	enlaceEste = nodo;
}


nodoMulti* nodoMulti::getEnlaceSur() {
	return enlaceSur;
}
void nodoMulti::setEnlaceSur(nodoMulti *nodo) {
	enlaceSur = nodo;
}


nodoMulti* nodoMulti::getEnlaceOeste() {
	return enlaceOeste;
}
void nodoMulti::setEnlaceOeste(nodoMulti *nodo) {
	enlaceOeste = nodo;
}

int nodoMulti::getCantidadNodos() {
	return cantidadNodosMulti;
}

string nodoMulti::toString() {
	stringstream ss;
	ss << "Nodo: " << this << endl;
	ss << "\tNorte: " << enlaceNorte << endl;
	ss << "\tOeste: " << enlaceOeste << endl;
	ss << "\tEste:  " << enlaceEste << endl;
	ss << "\tSur:   " << enlaceSur << endl;
	return ss.str();
}

