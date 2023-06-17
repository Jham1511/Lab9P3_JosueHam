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

void estadoWallet(Wallet* carte) {
	cout << "Nombre de usuario: " << carte->getNombre() << endl
		<< "Cantidad de DogeCoin: " << carte->getDogeCoin() << endl
		<< "Cantidad de Ethereum: " << carte->getEthereum() << endl
		<< "Cantidad de WalterCoin: " << carte->getWalterCoin() << endl;
}
void estadoCuentaUsuario(UsuarioPaypal* account) {
	cout << "Nombre: " << account->getNombreUsuario() << endl
		<< "Numero de Identidad: " << account->getNumIdentidad() << endl
		<< "Saldo: " << account->getSaldo() << endl;
}
bool contrasenaValida(string passwordWallet) {
	int contadorCaracterEspecial = 0;
	bool tieneNumeros = false; //Sirve para validar si la contraseña tiene numeros
	bool tieneLetras = false;
	bool valido = false;
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
			valido = true;
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
			valido = true;
		}
	}
	return valido;
}
int main()
{
	int opcionIngresada = menu();
	Paypal* cuenta = new Paypal();
	Wallet* cartera = new Wallet;
	vector <Wallet*> carteras;
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

			cartera->setNombreUsuario(nomUsuarioWallet);

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
					cartera->setCuenta(cuenta);
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
			
			if (contrasenaValida(passwordWallet) == true)
			{
				cartera->setContrasena(passwordWallet);
			}
			
			carteras.push_back(cartera);
			cout << "Cartera creada correctamente" << endl;
			break;
		}
		case 3: {
			
			break;
		}
		case 4: {
			cout << "--Iniciar Sesion en Paypal--" << endl;
			cout << "Ingrese su usuario" << endl;
			string nomUsuario;
			cin >> nomUsuario;
			cout << "Ingrese su contrasena" << endl;
			string contrasena;
			cin >> contrasena;
			for (int i = 0; i < cuenta->getUsuarios().size(); i++)
			{
				if (nomUsuario == cuenta->getUsuarios()[i]->getNombreUsuario() && contrasena == cuenta->getUsuarios()[i]->getPassword())
				{
					UsuarioPaypal* account = cuenta->getUsuarios()[i];
					cout << "--Bienvenido--" << endl
						<< "1 -> Ver estado de cuenta" << endl
						<< "2 -> Hacer deposito a mi cuenta propia" << endl
						<< "3 -> Hacer retiro de mi cuenta" << endl
						<< "4 -> Ver historial de cuenta" << endl
						<< "5 -> Salir" << endl
						<< "Seleccione" << endl;
					int seleccionPaypal;
					cin >> seleccionPaypal;
					switch (seleccionPaypal)
					{
					case 1: {
						estadoCuentaUsuario(account);
						printf("\n");
						break;
					}
					case 2: {
						cout << "Ingrese la cantidad que desea depositar" << endl;
						double deposito;
						cin >> deposito;

						double saldoActual = account->getSaldo();
						account->setSaldo(saldoActual + deposito);
						double saldoActualizado = account->getSaldo();
						cout << "Nuevo balance: " << saldoActualizado;
						break;
					}
					case 3: {
						cout << "Ingrese la cantidad que desea retirar" << endl;
						double retiro;
						cin >> retiro;

						double saldoActual = account->getSaldo();
						account->setSaldo(saldoActual - retiro);
						double saldoActualizado = account->getSaldo();
						cout << "Nuevo balance: " << saldoActualizado;
						break;
					}
					default:
						break;
					}
				}
				else {
					cout << "Datos invalidos" << endl;
				}
			}
			break;
		}
		case 5: {
			cout << "--Iniciar Sesion Wallet--" << endl;
			cout << "Ingrese su usuario" << endl;
			string nomUsuario;
			cin >> nomUsuario;
			cout << "Ingrese su contrasena" << endl;
			string contrasena;
			cin >> contrasena;
			for (int i = 0; i < carteras.size(); i++)
			{
				if (nomUsuario == carteras[i]->getNombre() && contrasena == carteras[i]->getContrasena())
				{
					Wallet* billetera = carteras[i];
					cout << "--Bienvenido--" << endl
						<< "1 -> Ver estado de cuenta" << endl
						<< "2 -> Comprar Cryptos" << endl
						<< "3 -> Vender Cryptos" << endl
						<< "4 -> Salir" << endl
						<< "Seleccione" << endl;
					int seleccionWallet;
					cin >> seleccionWallet;
					switch (seleccionWallet)
					{
					case 1: {
						estadoWallet(billetera);
						break;
					}
					default:
						break;
					}

				}
				else {
					cout << "Datos invalidos" << endl;
				}
			}
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