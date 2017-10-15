#include "vista.h"



vista::vista()
{
	
}
int vista::menuPrincipal() {
	int opc;
	cout << "==================================" << endl;
	cout << "============BIENVENIDO============" << endl;
	cout << "==================================" << endl;
	cout << "1- Jugar " << endl;
	cout << "2- Salir" << endl;
	cout << "==================================" << endl;
	cout << "Digite la opcion: " << endl;
	cin >> opc;
	while (opc < 1 || opc > 2)
	{
		cout << "Error" << endl;
		cout << "Digite un valor entre 1-2" << endl;
		opc = menuPrincipal();
	}
	return opc;
}
int vista::tipoJuego() {
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
void vista::mostrarGanador(int numeroG, string carton ,string pila) {
	cout << " ________________" << endl;
	cout << "|Ganador Numero  |" << endl;
	cout << "|"  << numeroG <<"             |" << endl;
	cout << "|________________|" << endl<<endl;
	cout << " ________________" << endl;
	cout << "| Carton Ganador |" << endl;
	cout << "|________________|" << endl;
	cout << carton << endl<<endl;
	cout << " _____________________" << endl;
	cout << "|Numeros que salieron |" << endl;
	cout << "|_____________________|" << endl;
	cout << pila << endl;
}
void vista::serJugador(int n) {
	cout << "==========================" << endl;
	cout << "---Jugador Numero"<<n<<"--" << endl;
}

void vista::ventanaBuscNumero(int num) {
	cout << "-------------------------------------" << endl;
	cout << " ________________" << endl;
	cout << "|" << num << "             |" << endl;
	cout << "|                |" << endl;
	cout << "|________________|" << endl;

}
void vista::ventanaFinal()
{

	cout << "==================================" << endl;
	cout << "==GRACIAS POR USAR LA APLICACION==" << endl;
	cout << "==========VUELVA PRONTO===========" << endl;
	cout << "==================================" << endl;
}

vista::~vista()
{
}
