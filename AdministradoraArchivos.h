#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Paypal.h"
using namespace std;
class AdministradoraArchivos
{
private:
	fstream archivo;
public: 
	AdministradoraArchivos();
	AdministradoraArchivos(fstream);
	void cargarUsuarios(Paypal*);
};