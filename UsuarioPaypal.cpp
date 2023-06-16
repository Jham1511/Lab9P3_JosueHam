#include "UsuarioPaypal.h"

string UsuarioPaypal::getNombreUsuario() {
	return this->nombreUsuario;
}

void UsuarioPaypal::setNombreUsuario(string nomUsuario) {
	this->nombreUsuario = nomUsuario;
}