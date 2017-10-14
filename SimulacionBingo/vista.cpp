#include "vista.h"



vista::vista()
{
	
}
int vista::menuPrincipal() {
	int opc;
	cout << "==================================" << endl;
	cout << "============BIENVENIDO============" << endl;
	cout << "==================================" << endl;
	cout << "1- Jugadas " << endl;
	cout << "2- Jugar " << endl;
	cout << "3- Salir" << endl;
	cout << "==================================" << endl;
	cout << "Digite la opcion: " << endl;
	cin >> opc;
	while (opc < 1 || opc > 3)
	{
		cout << "Error" << endl;
		cout << "Digite un valor entre 1-3" << endl;
		opc = menuPrincipal();
	}
	return opc;
}
void vista::mostrarGanador(int numeroG, string carton) {
	cout << "Ganador" << endl;
	cout << numeroG << endl<<endl;

	cout << "Carton Ganador" << endl;
	cout << carton << endl;
}
void vista::serJugador(int n) {
	cout << "==========================" << endl;
	cout << "---Jugador Numero"<<n<<"--" << endl;
}

void vista::ventanaBuscNumero(int num) {
	cout << "-------------------------------------" << endl;
	cout << " ________________" << endl;
	cout << "|  " << num << " |" << endl;
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
