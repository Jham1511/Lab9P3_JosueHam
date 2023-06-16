#include "Paypal.h"
#include <fstream>
Paypal::Paypal() {
	
}

Paypal::~Paypal() {
	
}

void Paypal::agregarUsuario(UsuarioPaypal usuario) {
	cout << "Llegue aqui" << endl;
	usuarios->push_back(usuario);
	cout << "Usuario agregado correctamente" << endl;
}

void Paypal::eliminarUsuario(UsuarioPaypal usuario, int posicion) {
	//usuarios.erase(usuarios.begin() + posicion);
	cout << "Usuario eliminado correctamente" << endl;
}

void Paypal::crearCuenta(UsuarioPaypal user) {
	int contadorCaracterEspecial = 0;
	bool tieneNumeros = false; //Sirve para validar si la contraseña tiene numeros
	bool tieneLetras = false;

	string nomUsuario;
	cout << "Ingrese el nombre de usuario, tiene que ser unico: " << endl;
	cin >> nomUsuario; 

	cout << "Ingrese su numero de identidad: " << endl;
	string numIdentidad;
	cin >> numIdentidad;

	cout << "Ingrese la contrasena de la cuenta, tiene que ser alfanumerica" << endl;
	string password;
	cin >> password;

	
	int sizeUsuarios = usuarios->size();
	for (int i = 0; i < usuarios->size(); i++)
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
		else if (numIdentidad == usuarios[i]->getNumIdentidad()) {
			cout << "El numero de identidad ya esta en el sistema: " << endl
				<< "Ingrese de nuevo el numero de identidad" << endl;
			cin >> numIdentidad;
		}
		else if (numIdentidad != usuarios[sizeUsuarios - 1 - i].getNombreUsuario()) {
			user->setNumIdentidad(numIdentidad);
		}
		else if (password.length() >= 7) {
			for (char caracter : password)
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
				user->setNumIdentidad(password);
			}
		}
		else {
			while (password.length() < 7) {
				cout << "Ingrese la contrasena de la cuenta, tiene que ser alfanumerica" << endl;
				cin >> password;
			}
			for (char caracter : password)
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
				user->setNumIdentidad(password);
			}
		}
		
		string ID = numIdentidad + ".lab";
		fstream archivoUsuario(ID, ios::in | ios::binary);
		if (archivoUsuario.fail())
		{
			cout << "No se pudo crear el archivo" << endl;
		}
		else {
			archivoUsuario.write(reinterpret_cast<const char*> (&user), sizeof(Paypal));
			archivoUsuario.close();
		}
		
		
		agregarUsuario(user);
		
}