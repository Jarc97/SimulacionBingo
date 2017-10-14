#pragma once
#include "iostream"
#include "sstream"
#include "ostream"
using namespace std;
template <class T>
class Nodo {
public:
	Nodo(Nodo<T>*, T*);
	~Nodo();
	virtual Nodo<T>* siguiente() const;
	virtual void fijarSiguiente(Nodo<T>*);
	virtual T* obtenerInfo() const;
	virtual string toString()const;
private:
	Nodo<T>* _siguiente;
	T *_info;
};
template <class T>
Nodo<T>::Nodo(Nodo<T>* sig, T* inf)
	: _siguiente(sig), _info(inf) {
}
template <class T>
Nodo<T>* Nodo<T>::siguiente() const {
	return _siguiente;
}
template <class T>
void Nodo<T>::fijarSiguiente(Nodo<T>* sig) {
	_siguiente = sig;
}
template <class T>
Nodo<T>:: ~Nodo() {

}
template <class T>
string Nodo<T>::toString() const
{
	return _info->toString();
}

template <class T>
T* Nodo<T>::obtenerInfo()const {
	return _info;
}