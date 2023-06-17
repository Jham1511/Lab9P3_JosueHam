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
	Paypal* cuenta = new Paypal();
	Wallet* cartera = new Wallet;
	while (opcionIngresada!= 6) {
		switch (opcionIngresada) {
		case 1: {
			cout << "Bienvenido a crear cuenta de Paypal" << endl;
			printf("\n");
			
			UsuarioPaypal* user = new UsuarioPaypal;
			cuenta->crearCuenta(user);
			break;
		}
		case 2: {
			cout << "Bienvenido a crear wallet" << endl;
			printf("\n");
			
			cout << "Ingrese el nombre de usuario para la wallet" << endl;
			string nomUsuarioWallet;
			cin >> nomUsuarioWallet;

			cartera->
			cout << "Tiene una cuenta de Paypal?" << endl
				<< "1 -> Si" << endl
				<< "2 -> No" << endl;
			int cuentaExistente;
			cin >> cuentaExistente;
			switch (cuentaExistente)
			{
			case 1: {
				cout << "Ingrese el nombre de usuario de la cuenta" << endl;
				string nomUsuarioPaypal;
				cin >> nomUsuarioPaypal;
				int sizeUsuarios = cuenta->getUsuarios().size();

				for (int i = 0; i < sizeUsuarios; i++)
				{
					while (nomUsuarioPaypal != cuenta->getUsuarios()[i]->getNombreUsuario()) {
						cout << "Ingrese el nombre de usuario de la cuenta de nuevo" << endl;
						cin >> nomUsuarioPaypal;
					}

				}
				break;
			}
			case 2: {
				

				cout << "Desea salir o crear una cuenta?: " << endl
					<< "1 -> Crear Cuenta" << endl
					<< "2 -> Salir" << endl;
				int decisionCuenta;
				cin >> decisionCuenta;
				if (decisionCuenta == 1)
				{
					UsuarioPaypal* usuario = new UsuarioPaypal;
					cuenta->crearCuenta(usuario);
				}
				else {
					break;
				}
				break;
			}
			}//Fin switch si tiene cuenta
			cout << "Ingrese la contrasena de la wallet" << endl;
			string passwordWallet;
			cin >> passwordWallet;
			int contadorCaracterEspecial = 0;
			bool tieneNumeros = false; //Sirve para validar si la contraseña tiene numeros
			bool tieneLetras = false;
			if (passwordWallet.length() >= 7) {
				for (char caracter : passwordWallet)
				{
					if (caracter >= 33 && caracter <= 47)
					{
						contadorCaracterEspecial++;
					}
					else if (caracter >= 48 && caracter <= 57) {
						tieneNumeros = true;
					}
					else if (caracter >= 65 && caracter <= 90)
					{
						tieneLetras = true;
					}
				}
				if (contadorCaracterEspecial > 1 && tieneLetras && tieneNumeros)
				{
					
				}
			}
			else {
				while (passwordWallet.length() < 7) {
					cout << "Ingrese la contrasena de la cuenta, tiene que ser alfanumerica" << endl;
					cin >> passwordWallet;
				}
				for (char caracter : passwordWallet)
				{
					if (caracter >= 33 && caracter <= 47)
					{
						contadorCaracterEspecial++;
					}
					else if (caracter >= 48 && caracter <= 57) {
						tieneNumeros = true;
					}
					else if (caracter >= 65 && caracter <= 90)
					{
						tieneLetras = true;
					}
				}
				if (contadorCaracterEspecial > 1 && tieneLetras && tieneNumeros)
				{
					
				}
			}
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
			cuenta->~Paypal();
			cartera->~Wallet();
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}