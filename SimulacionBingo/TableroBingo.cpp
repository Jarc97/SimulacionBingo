#include "TableroBingo.h"

TableroBingo::TableroBingo(int columnas, int filas) {
	Matriz(columnas, filas);
	tipoJuego = 0;
	marcados = 0;
	completo = false;
}
void TableroBingo::setTipoJuego(int j) {
	tipoJuego = j;
}
void TableroBingo::buscarSegunHorizontal(int num) {
	for (int i = 0; i < filas; i++) {
		if ((*this)(i, 0)->getValor()==num) {
			(*this)(i, 0)->setMarcado(true);
			marcados++;
		}
	}
	if (marcados==5) {
		completo = true;
	}
	}
bool TableroBingo::getCompleto() {
	return completo;
}
void TableroBingo::buscarSegunVertical(int num) {
	for (int i = 0; i < columnas; i++) {
		if ((*this)(0, i)->getValor() == num) {
			(*this)(0, i)->setMarcado(true);
			marcados++;
		}
	}
	if (marcados == 5) {
		completo = true;
	}
}
void TableroBingo::buscarSegunDiagonal(int num) {}
void TableroBingo::buscarSegunC(int num) {}
void TableroBingo::buscarSegunX(int num) {}
void TableroBingo::buscarSegunU(int num) {}
void TableroBingo::buscarSegunO(int num) {}
void TableroBingo::buscarSegunBingo(int num) {}
void TableroBingo::busqueda(int num) {
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
TableroBingo::~TableroBingo()
{
}
