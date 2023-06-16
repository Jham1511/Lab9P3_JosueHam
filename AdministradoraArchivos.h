#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class AdministradoraArchivos
{
private:
	fstream archivo;
public: 
	AdministradoraArchivos();
	AdministradoraArchivos(fstream);
	void cargarUsuarios();
};