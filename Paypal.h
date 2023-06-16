#pragma once
#include <iostream>
#include <vector>
#include "UsuarioPaypal.h"
using namespace std;
class Paypal
{
private: 
	vector<UsuarioPaypal> usuarios;
public:
	Paypal();
	~Paypal();
	void agregarUsuario();
	void eliminarUsuario();
	void crearCuenta(UsuarioPaypal*);
};