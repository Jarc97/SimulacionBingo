#include <iostream>

#include "TableroBingo.h"
#include "NodoMulti.h"
#include "Numero.h"

int main() {
	// TableroBingo *tb = new TableroBingo();

	
	Matriz *m = new Matriz(5, 5);
	cout << NodoMulti::getCantidadNodos() << endl;
	


	//Matriz &mm = *m;
	//mm(1, 1);

	//m->operator()(2, 3);


	// Toda la matriz empieza con datos en 0
	// Poner un 9 en la posicion (0,0)
	(*m)(0, 0, 9);
	// Obtener el numero guardado en 0,0
	Numero *num = (*m)(0, 0);
	cout << num->getValor() << endl;

	cout << m->toString() << endl;

	system("PAUSE");
	return 0;
}