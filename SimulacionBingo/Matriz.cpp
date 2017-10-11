#include "Matriz.h"
#include "Numero.h"

Matriz::Matriz() {
	origen = nullptr;
	tipoJuego = 0;
	marcados = 0;
	completo = false;
}

Matriz::Matriz(int columnas, int filas) {
	tipoJuego = 0;
	marcados = 0;
	completo = false;
	this->columnas = columnas;
	this->filas = filas;

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
void Matriz::llenarPorFila(int fil, int inicio, int final) {
	int bing[5];
	for (int i = 0; i < columnas; i++) {
		(*this)(fil, i)->setValor(inicio + rand() % (final + 1 - inicio));
		if (i > 1) {
			for (int k = 0; k < 5; k++) {
				if (bing[k] == (*this)(fil, i)->getValor()) {
					(*this)(fil, i)->setValor(inicio + rand() % (final + 1 - inicio));
				}
			}
		}
		bing[i] = (*this)(fil, i)->getValor();
	}
	ordenar(fil,0,4);
}
void Matriz::ordenar(int fil,int izq, int der) {
	int i, j; /* variables indice del vector */
	int elem; /* contiene un elemento del vector */
	i = izq;
	j = der;
	elem = (*this)(fil, (izq+der)/2)->getValor();
	do
	{
		while ((*this)(fil, i)->getValor() < elem) //recorrido del vector hacia la derecha
			i++;
		while (elem < (*this)(fil, j)->getValor()) // recorrido del vector hacia la izquierda
			j--;
		if (i <= j) /* intercambiar */
		{
			int aux; /* variable auxiliar */
			aux = (*this)(fil, i)->getValor();
			(*this)(fil, i)->setValor((*this)(fil, j)->getValor());
			(*this)(fil, j)->setValor(aux);
			i++;
			j--;
		}
	} while (i <= j);
	if (izq < j) { ordenar(fil, izq, j); } //Llamadas recursivas
	if (i < der) { ordenar(fil, i, der); }
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
void Matriz::llenar() {
	
	llenarPorFila(0,1,15);
	llenarPorFila(1,16,30);
	llenarPorFila(2,31,45);
	llenarPorFila(3,46,60);
	llenarPorFila(4,61,75);
	
}
string Matriz::toString() {
	Numero *n = nullptr;
	stringstream ss;
	
	for (int i = 0; i < columnas; i++) {
		for (int j = 0; j < filas; j++) {
			if ((*this)(j, i)->getMarcado()==true) {
				ss << "{"<< (*this)(j, i)->getValor()<<"}" << " ";
			}
			else {
				ss << (*this)(j, i)->getValor() << " ";
			}
		}
		ss << endl;
	}

	return ss.str();
}


void Matriz::setTipoJuego(int j) {
	tipoJuego = j;
}
void Matriz::buscarSegunHorizontal(int num) {
	for (int i = 0; i < filas; i++) {
		if ((*this)(i, 0)->getValor() == num) {
			(*this)(i, 0)->setMarcado(true);
			marcados++;
		}
	}
	if (marcados == 5) {
		setCompleto(true);
	}
}
bool Matriz::getCompleto() {
	return completo;
}
void Matriz::setCompleto( bool m) {
	completo = m;
}
void Matriz::buscarSegunVertical(int num) {
	for (int i = 0; i < columnas; i++) {
		if ((*this)(0, i)->getValor() == num) {
			(*this)(0, i)->setMarcado(true);
			marcados++;
		}
	}
	if (marcados == 5) {
		setCompleto(true);
	}
}
void Matriz::buscarSegunDiagonal(int num) {}
void Matriz::buscarSegunC(int num) {}
void Matriz::buscarSegunX(int num) {}
void Matriz::buscarSegunU(int num) {}
void Matriz::buscarSegunO(int num) {}
void Matriz::buscarSegunBingo(int num) {}
void Matriz::busqueda(int num) {
	switch (tipoJuego)
	{
	case 1:
		buscarSegunHorizontal(num);
		break;
	case 2:
		buscarSegunVertical(num);
		break;
	case 3:
		buscarSegunDiagonal(num);
		break;
	case 4:
		buscarSegunC(num);
		break;
	case 5:
		buscarSegunX(num);
		break;
	case 6:
		buscarSegunU(num);
		break;
	case 7:
		buscarSegunO(num);
		break;
	case 8:
		buscarSegunBingo(num);
		break;
	}
}