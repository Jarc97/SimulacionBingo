#include <iostream>
#include <sstream>
#include "nodo.h"

using namespace std;
template<class T>
class Lista {
public:
	virtual int numElementos() const;
	Lista();
	virtual void agregar(T*);
	bool estaVacia() const;
	virtual std::string toString() const;

private:
	Nodo<T>* primero;
};
template<class T>
Lista<T>::Lista() : primero(NULL) {
}
template<class T>
int Lista<T>::numElementos() const {
	int r = 0;
	Nodo<T>* cursor = primero;
	while (cursor != NULL) {

		cursor = cursor->siguiente();
		r++;
	}
	return r;
}
template<class T>
void Lista<T>::agregar(T* x) {
	if (primero == NULL) {
		primero = new Nodo<T>(NULL, x);
	}
	else {
		Nodo<T>* cursor = primero;
		while (cursor->siguiente() != NULL) {
			cursor = cursor->siguiente();
		}
		cursor->fijarSiguiente(new Nodo<T>(NULL, x));
	}
}

template<class T>
bool Lista<T>::estaVacia() const
{
	return primero == NULL;
}
template<class T>
string Lista<T>::toString() const {
	stringstream r;
	Nodo<T>* cursor = primero;
	while (cursor != NULL) {
		r <<"Jugada "<<numElementos()<<" "<< cursor->toString();
		if ((cursor = cursor->siguiente()) != NULL) {
			r << "  " << endl;
		}
	}
	return r.str();
}
