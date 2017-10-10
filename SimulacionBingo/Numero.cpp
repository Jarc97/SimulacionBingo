#include "Numero.h"

Numero::Numero() {
	valor = 0;
	marcado = false;
}

Numero::~Numero(){}

void Numero::setValor(int v) {
	valor = v;
}

int Numero::getValor() {
	return valor;
}


