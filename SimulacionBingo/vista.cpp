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
	while (opc < 1 || opc>3)
	{
		cout << "Error" << endl;
		cout << "Digite un valor entre 1-3" << endl;
		opc = menuPrincipal();
	}
	return opc;
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
