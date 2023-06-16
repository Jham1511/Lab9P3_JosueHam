#include "Paypal.h"
Paypal::Paypal() {
	
}

Paypal::~Paypal() {
	
}

void Paypal::agregarUsuario() {

}

void Paypal::crearCuenta(UsuarioPaypal* user) {
	string nomUsuario;
	cout << "Ingrese el nombre de usuario, tiene que ser unico: " << endl;
	cin >> nomUsuario; 
	cout << "Ingrese su numero de identidad: " << endl;
	string numIdentidad;
	cin >> numIdentidad;
	int sizeUsuarios = usuarios.size();
	for (int i = 0; i < usuarios.size(); i++)
	{
		if (nomUsuario == usuarios[i].getNombreUsuario())
		{
			cout << "El nombre ingresado ya esta en el sistema: " << endl
				<< "Ingrese de nuevo el nombre" << endl;
			cin >> nomUsuario;
		}
		else if(nomUsuario != usuarios[sizeUsuarios - 1 - i].getNombreUsuario()) {
			user->setNombreUsuario(nomUsuario);
		}
		else if (numIdentidad == usuarios[i].getNumIdentidad()) {
			cout << "El numero de identidad ya esta en el sistema: " << endl
				<< "Ingrese de nuevo el numero de identidad" << endl;
			cin >> numIdentidad;
		}
		else if (numIdentidad != usuarios[sizeUsuarios - 1 - i].getNombreUsuario()) {

		}
	}
}