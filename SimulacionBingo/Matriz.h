#pragma once

#include "NodoMulti.h"

using namespace std;
class Numero;

class Matriz {
protected:
	NodoMulti *origen;
	int columnas, filas;
	int tipoJuego;
	bool juegoCompletado;
	int marcados;
public:
	bool GetJuegoCompletado();
	void SetJuegoCompletado(bool);
	void llenar();
	Matriz();
	Matriz(int columnas, int filas);
	~Matriz();
	 void llenarPorFila(int fil, int inicio, int final);
	 void ordenar(int fil, int ind_izq, int ind_der);
	// Sobrecarga para modificar elementos en la Matriz
	bool operator()(int columna, int fila, int num);

	// Sobrecarga para buscar elementos en la Matriz
	Numero* operator()(int columna, int fila);

	string toString();

	///-------------------------------
	
	void setTipoJuego(int j);
	void busqueda(int num);
	void buscarSegunHorizontal(int num);
	void buscarSegunVertical(int num);
	void buscarSegunDiagonal(int num);
	void buscarSegunC(int num);
	void buscarEquis(int num );
	void buscarSegunU(int num);
	void buscarSegunO(int num);
	void buscarSegunBingo(int num);
};

