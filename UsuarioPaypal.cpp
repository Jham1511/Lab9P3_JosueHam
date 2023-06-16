#include "UsuarioPaypal.h"
UsuarioPaypal::UsuarioPaypal() {
	this->nombreUsuario = "Sin asignar";
	this->numeroIdentidad = "Sin asignar";
	this-> password = "Sin asignar";
	this->saldoCuenta = 0.0;
}

UsuarioPaypal::UsuarioPaypal(string nomUsuario, string identidad, string contra) {
	this->nombreUsuario = nomUsuario;
	this->numeroIdentidad = identidad;
	this->password = contra;
	this->saldoCuenta = 0.0;
}

UsuarioPaypal::~UsuarioPaypal() {
	delete &nombreUsuario, &numeroIdentidad, &password, &saldoCuenta;
}
string UsuarioPaypal::getNombreUsuario() {
	return this->nombreUsuario;
}

void UsuarioPaypal::setNombreUsuario(string nomUsuario) {
	this->nombreUsuario = nomUsuario;
}

string UsuarioPaypal::getNumIdentidad() {
	return this->numeroIdentidad;
}

string UsuarioPaypal::getNumIdentidad() {
	return this->numeroIdentidad;
}

double UsuarioPaypal::getSaldo() {
	return this->saldoCuenta;
}

void UsuarioPaypal::setNumIdentidad(string identidad) {
	this->numeroIdentidad = identidad;
}

void UsuarioPaypal::setPassword(string contra) {
	this->password = contra;
}

void UsuarioPaypal::setSaldo(double nueSaldo) {
	this->saldoCuenta = nueSaldo;
}