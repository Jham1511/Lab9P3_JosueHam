#pragma once
#include <iostream>
#include <string>
using namespace std;
class UsuarioPaypal
{
private: 
	string nombreUsuario, numeroIdentidad, password;
	double saldoCuenta;
public:
	UsuarioPaypal();
	UsuarioPaypal(string, string, string);
	~UsuarioPaypal();
	void historial();
	string getNombreUsuario();
	void setNombreUsuario(string);
	string getNumIdentidad();
	void setNumIdentidad(string);
	string getPassword();
	void setPassword(string);
	double getSaldo();
	void setSaldo(double);
};