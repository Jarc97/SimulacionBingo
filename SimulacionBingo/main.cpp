#include <iostream>

#include "Matriz.h"
#include "NodoMulti.h"

int main() {
	Matriz *m = new Matriz(5, 5);
	cout << NodoMulti::getCantidadNodos() << endl;
	// cout << m->toString() << endl;
	system("PAUSE");
	return 0;
}