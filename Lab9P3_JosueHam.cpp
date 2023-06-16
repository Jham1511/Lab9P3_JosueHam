#include <iostream>
#include "Paypal.h"
#include "UsuarioPaypal.h"
#include "AdministradoraArchivos.h"
#include "Wallet.h"
using namespace std;
int menu() {
	cout << "\nMenu del Programa" << endl
		<< "1 -> Crear Cuenta de Paypal" << endl
		<< "2 -> Crear Wallet" << endl
		<< "3 -> Cargar Informacion" << endl
		<< "4 -> Acceder a Paypal" << endl
		<< "5 -> Acceder a Wallet" << endl
		<< "6 -> Salir" << endl
		<< "Ingrese la opcion que desea: " << endl;
	int numero;
	cin >> numero;
	return numero;
}

int main()
{
	int opcionIngresada = menu();
	while (opcionIngresada!= 6) {
		switch (opcionIngresada) {
		case 1: {
			cout << "Bienvenido a crear cuenta de Paypal" << endl;
			printf("\n");
			Paypal* cuenta = new Paypal();
			UsuarioPaypal user;
			cuenta->crearCuenta(user);
			
			break;
		}
		case 2: {

			break;
		}
		case 3: {
			
			break;
		}
		case 4: {

			break;
		}
		case 5: {

			break;
		}
		default:
			cout << "..." << endl;
			printf("\n");
			
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}