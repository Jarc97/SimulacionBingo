#include <iostream>
#include <sstream>
using namespace std;

template<class T>
class Pila {
private:
	int nelementos;
	T* vec;
	int limite;
public:
	Pila(int nelem = 1500); //Constructor
	bool Poner(const T& valorInsertado);
	bool Sacar(T& valorExtraido);
	bool Vacia();
	bool Llena();
	T& Top();
	~Pila();
};

template<class T>
Pila<T>::Pila(int nelem= 1500) {
	nelementos = nelem;
	limite = -1;
	vec = new T[nelementos];
}

template<class T> //Push(...)
bool Pila<T>::Poner(const T& valorInsertado) {
	if (!Llena()) {
		vec[++limite] = valorInsertado;
		return true;
	}
	else
		return false;
}

template<class T> //Pop(...)
bool Pila<T>::Sacar(T& valorExtraido) {
	if (!Vacia()) {
		valorExtraido = vec[limite--];
		return true;
	}
	else
		return false;
}

template<class T>
bool Pila<T>::Vacia() {
	return limite == -1;
}

template<class T>
bool Pila<T>::Llena() {
	return limite == nelementos - 1;
}

template<class T> //Ver elemento de la cima de la pila.
T& Pila<T>::Top() {
	if (limite != -1 && limite < nelementos)
		return vec[limite];
}

template<class T>
Pila<T>::~Pila() {
}