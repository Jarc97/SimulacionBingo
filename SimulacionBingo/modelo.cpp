#include "modelo.h"

modelo::modelo()
{
	pilaNumeros = new Pila<int>();
	simula = new jugada(0,0,0);
	bingo = false;
    this->Jganador= NULL;
	this->cartonGanador= NULL;
	ultimoNumero = 0;
}
void modelo:: iniciarJugada() {
	system("cls");
	int cantJ = 0, cantMax=0;
	int tipoJ = 0;
	// int ultimoNum = 0;
	// ultimoNumero = &ultimoNum;
	cout << "Datos Iniciales " << endl;
	cout << "Digite la cantidad de jugadores ";
	cin >> cantJ;
	cout << "Digite la cantidad maxima de cartones por jugador ";
	cin >> cantMax;
	tipoJ = vista::tipoJuego();

	// Variables "globales" para los threads de la simulacion y servidor.
	// Se pasan por referencia a ambos para su comunicacion.
	// bool simulacionTerminada = false;

	// Dividir la ejecucion de la simulacion y el servidor
	thread thread_simulacion(&modelo::simulacion, this, cantJ, cantMax, tipoJ, std::ref(bingo));
	thread thread_servidor(&modelo::servidor, this, &bingo, &cantJ, &cantMax, &ultimoNumero);
	thread_simulacion.join();
	thread_servidor.join();
	cout << "Termina Simulacion" << endl;
	system("pause");
}


void modelo::simulacion(int cantJ, int cantMax, int tipoJ, bool &simTerminada) {
	simula = new jugada(cantJ, cantMax, tipoJ);
	iniciarSimulacion();
	// simTerminada = true;
}

void modelo::servidor(bool *simTerminada, int *cantJ, int *cantMax, int *ultimoNum) {
	// Abrir una ventana nueva del buscador
	// ShellExecute(NULL, "open", "http://localhost:9001", NULL, NULL, SW_SHOWNORMAL);
	system("start http://localhost:9001");

	try
	{
		boost::asio::io_service io_service;
		tcp_server server(io_service, simTerminada, cantJ, cantMax, ultimoNum);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
				iniciarJugada();
				break;
			case 2: vista::ventanaFinal();
				break;

			}
		} while (opc != 2);
		
	
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
				this->Jganador = simula->obtenerJugadores()[i];
				this->cartonGanador = simula->obtenerJugadores()[i]->getCartones()[k];
			}
		}

	}
	return op;
}
void modelo::iniciarSimulacion() {
	int comienzo = 0;
	int fin = 74;
	int esfera[75];
	int numero = 0;
	int lop = 0;
	for (int k = 1; k <= 75;k++) {
		esfera[k-1] = k;
	}
	while (ganador()==false) {
		system("cls");
		int numeroObtenido = comienzo + rand() % (fin+ 1 - comienzo);
		numero = esfera[numeroObtenido];
		do {
			numeroObtenido = comienzo + rand() % (fin  + 1 - comienzo);
			numero = esfera[numeroObtenido];
		} while (numero == 0);
		esfera[numeroObtenido] = 0;

		///////////
		ultimoNumero = numero;
		//////////
		
		simula->buscar(numero);
		vista::ventanaBuscNumero(numero);
		pilaNumeros->Poner(numero);
		
		cout << simula->toString() << endl;
		// VELOCIDAD DE GENERACION DE NUMEROS
		Sleep(2000);
		if (ganador() == true) {
			system("cls");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "                 ¡ BINGO !                             " << endl;
			bingo = true;
			system("pause");
		}
	}
	
	if (ganador() == true) {
		system("cls");
		vista::mostrarGanador(this->Jganador->getNumero(), this->cartonGanador->toString(),pilaNumeros->toString());
		cout << "BINGO !!" << endl;
		system("pause");
		//procesoMenuPrincipal();
		return;
	}
}


modelo::~modelo()
{
}
