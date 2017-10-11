#pragma once
#include "Matriz.h"

static const int B = 0;
static const int I = 1;
static const int N = 2;
static const int G = 3;
static const int O = 4;

class TableroBingo : public Matriz {
private:
	int tipoJuego;
	int marcados;
	bool completo;
public:
	TableroBingo(int columnas, int filas);
	bool getCompleto();
	void setTipoJuego(int j);
	void busqueda(int num);
	void buscarSegunHorizontal(int num);
	void buscarSegunVertical(int num);
	void buscarSegunDiagonal(int num);
	void buscarSegunC(int num);
	void buscarSegunX(int num);
	void buscarSegunU(int num);
	void buscarSegunO(int num);
	void buscarSegunBingo(int num);
	~TableroBingo();
};

