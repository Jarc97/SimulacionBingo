#include "modelo.h"



modelo::modelo()
{
	simula = new jugada(0,0,0);
	bingo = false;
}
void modelo:: iniciarJugada() {
	int cantJ = 0, cantMax=0;
	int tipoJ = 0;
	cout << "Datos Iniciales " << endl;
	cout << "Digite la cantidad de jugadores ";
	cin >> cantJ;
	cout << "Digite la cantidad maxima de cartones por jugador ";
	cin >> cantMax;
	tipoJ = tipoJuego();
	simula = new jugada(cantJ,cantMax,tipoJ);

	iniciarSimulacion();
}
int modelo::tipoJuego() {
	int opc;
	cout << "-----Tipo Juego------" << endl;
	cout << "1- Linea Horizontal " << endl;
	cout << "2- Linea Vertical" << endl;
	cout << "3- Linea Diagonal" << endl;
	cout << "4- Una figura C" << endl;
	cout << "5- Una figura X " << endl;
	cout << "6- Una figura U " << endl;
	cout << "7- Una figura O " << endl;
	cout << "8- BINGO (Carton Lleno) " << endl;
	cout << "==================================" << endl;
	cout << "Digite la opcion: " << endl;
	cin >> opc;
	while (opc < 1 || opc>8)
	{
		cout << "Error" << endl;
		cout << "Digite un valor entre 1-8" << endl;
		opc = tipoJuego();
	}
	return opc;
}
void modelo::verJugadas() {
}
void modelo::procesoMenuPrincipal() {
	
		int opc = 0;
		do
		{
			opc = vista::menuPrincipal();
			switch (opc)
			{
			case 1:
				verJugadas();
				break;
			case 2:
				iniciarJugada();
				break;
			case 5: vista::ventanaFinal();
				break;

			}
		} while (opc != 3);
	
}
void modelo::procesoInicio() {
	procesoMenuPrincipal();
	iniciarSimulacion();
}
void modelo:: iniciarSimulacion() {
	int comienzo = 1;
	int fin= 75;
	int numero = 0;
	while (bingo==false) {
		numero = comienzo + rand() % (fin+1  - 1);
		cout << numero << endl;
		if (simula->getGanador() != NULL) {
			bingo = true;
		}
	}
}
modelo::~modelo()
{
}
