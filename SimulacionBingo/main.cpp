#include <iostream>

#include "TableroBingo.h"
#include "NodoMulti.h"

int main() {
	// TableroBingo *tb = new TableroBingo();

	
	Matriz *m = new Matriz(5, 5);
	cout << NodoMulti::getCantidadNodos() << endl;
	cout << m->toString() << endl;

	cout << m->get(1, 1) << endl;

	// NodoMulti *n = m[1][2];
	// cout << n->getDato()->getValor();

	system("PAUSE");
	return 0;
}