#include "Numero.h"

Numero::Numero() {
	valor = 0;
	marcado = false;
}

Numero::~Numero(){}

void Numero::setValor(int v) {
	valor = v;
}
void Numero::setMarcado(bool t) {
	marcado = t;
}
bool Numero::getMarcado() {
	return  marcado;
}
int Numero::getValor() {
	return valor;
}


