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
	system("cls");
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
	system("cls");
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
			case 3: vista::ventanaFinal();
				break;

			}
		} while (opc != 3);
		
	
}
int modelo::serJugador() {
	int yo = NULL;
	yo = 1 + rand() % (simula->obtenerCantJugadores() + 1 - 1);
	if (simula->obtenerCantJugadores() ==2) {
		yo = 1;
	}
	return yo;
}

void modelo::procesoInicio() {
	procesoMenuPrincipal();
}
bool modelo::ganador() {
	bool op = false;
	for (int i = 0; i <simula->obtenerCantJugadores() ; i++) {
		for (int k = 0; k < simula->obtenerJugadores()[i]->getCantCartones(); k++) {
			if (simula->obtenerJugadores()[i]->getCartones()[k]->GetJuegoCompletado() == true) {
				op = true;
				simula->setGanador(simula->obtenerJugadores()[i]);
			}
		}

	}
	return op;
}
void modelo::iniciarSimulacion() {
	int comienzo = 1;
	int fin = 75;
	int esfera[75];
	int numero = 0;
	int lop = 0;
	int cant = 0;
	for (int k = 1; k <= 75;k++) {
		esfera[k] = k;
	}
	while (ganador()==false) {
		int numeroObtenido = comienzo + rand() % (fin+ 1 - comienzo);
		numero = esfera[numeroObtenido];
		do {
			numeroObtenido = comienzo + rand() % (fin  + 1 - comienzo);
			numero = esfera[numeroObtenido];
		} while (numero == 0);
		esfera[numeroObtenido] = 0;

		simula->buscar(numero);
		/*if () {
			bingo = true;
		}*/
		cant++;
		for (int k = 1; k <= 75; k++) {
			cout<< k<<" "<< esfera[k] << endl;
		}
		cout << simula->toString() << endl;
		system("pause");
	}

}


modelo::~modelo()
{
}
