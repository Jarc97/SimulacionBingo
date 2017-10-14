#pragma once
#include "modelo.h"
#include <iostream>
using namespace std;
class vista
{
private:
public:
	static int menuPrincipal();
	static void ventanaFinal();
	static void ventanaBuscNumero(int num);
	static void serJugador(int nom);
	static void mostrarGanador(int,string);
	vista();
	~vista();
};

