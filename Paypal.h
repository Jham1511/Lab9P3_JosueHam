#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "UsuarioPaypal.h"
using namespace std;
class Paypal
{
private: 
	vector<UsuarioPaypal*> usuarios;
public:
	Paypal();
	~Paypal();
	void agregarUsuario(UsuarioPaypal*);
	void eliminarUsuario(UsuarioPaypal, int);
	void crearCuenta(UsuarioPaypal* );
	vector<UsuarioPaypal*> getUsuarios();
};