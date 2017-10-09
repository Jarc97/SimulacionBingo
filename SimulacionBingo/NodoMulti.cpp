#include "NodoMulti.h"

// Inicializar variables static
int NodoMulti::cantidadNodosMulti = 0;

NodoMulti::NodoMulti() {
	cantidadNodosMulti++;

	dato = new Numero();
	enlaceNorte = nullptr;
	enlaceEste = nullptr;
	enlaceSur = nullptr;
	enlaceOeste = nullptr;
	cout << this << endl;
}

NodoMulti::~NodoMulti() {
	// DESTRUCCION DE LOS ENLACES (WIP)
	cantidadNodosMulti--;
}

Numero* NodoMulti::getDato() {
	return dato;
}


NodoMulti* NodoMulti::getEnlaceNorte() {
	return enlaceNorte;
}
void NodoMulti::setEnlaceNorte(NodoMulti *nodo) {
	enlaceNorte = nodo;
}


NodoMulti* NodoMulti::getEnlaceEste() {
	return enlaceEste;
}
void NodoMulti::setEnlaceEste(NodoMulti *nodo) {
	enlaceEste = nodo;
}


NodoMulti* NodoMulti::getEnlaceSur() {
	return enlaceSur;
}
void NodoMulti::setEnlaceSur(NodoMulti *nodo) {
	enlaceSur = nodo;
}


NodoMulti* NodoMulti::getEnlaceOeste() {
	return enlaceOeste;
}
void NodoMulti::setEnlaceOeste(NodoMulti *nodo) {
	enlaceOeste = nodo;
}

int NodoMulti::getCantidadNodos() {
	return cantidadNodosMulti;
}

int NodoMulti::operator[](int y) {
	NodoMulti *aux = this;
	int count = 0;
	while (count < y && aux->getEnlaceSur() != nullptr) {
		aux = aux->getEnlaceSur();
		count++;
	}
	return aux->getDato()->getValor();
}

string NodoMulti::toString() {
	stringstream ss;
	ss << "Nodo: " << this << endl;
	ss << "\tNorte: " << enlaceNorte << endl;
	ss << "\tOeste: " << enlaceOeste << endl;
	ss << "\tEste:  " << enlaceEste << endl;
	ss << "\tSur:   " << enlaceSur << endl;
	return ss.str();
}