#pragma once
#include "Matriz.h"

static const int B = 0;
static const int I = 1;
static const int N = 2;
static const int G = 3;
static const int O = 4;

class TableroBingo : public Matriz {
private:
	
public:
	TableroBingo(int columnas, int filas);
	~TableroBingo();
};

