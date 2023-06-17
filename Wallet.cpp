#include "Wallet.h"
Wallet::Wallet() {
	this->nombreUsuario = "NULL";
	this->password = "Sin declarar";
	this->cuenta = new Paypal();
	this->DogeCoin = 0.0;
	this->ethereum = 0;
	this->WalterCoin = 0;
}

Wallet::Wallet(string nombre, string contra, Paypal* cuenta) {
	this->nombreUsuario = nombre;
	this->password = contra;
	this->cuenta = cuenta;
	this->DogeCoin = 0.0;
	this->ethereum = 0;
	this->WalterCoin = 0;
}

Wallet::~Wallet() {
	delete[] cuenta;
	delete[] & nombreUsuario, & password, & DogeCoin, & ethereum, & WalterCoin;
}

void Wallet::setNombreUsuario(string nombre) {
	this->nombreUsuario = nombre;
}
void Wallet::setContrasena(string contra) {
	this->password = contra;
}
void Wallet::setCuenta(Paypal* cuenta) {
	this->cuenta = cuenta;
}
void Wallet::setEthereum(int eth) {
	this->ethereum = eth;
}
void Wallet::setDogeCoin(double doge) {
	this->DogeCoin = doge;
}
void Wallet::setWalterCoin(int walter) {
	this->WalterCoin = walter;
}

string Wallet::getNombre() {
	return this->nombreUsuario;
}
string Wallet::getContrasena() {
	return this->password;
}
int Wallet::getEthereum() {
	return this->ethereum;
}
int Wallet::getWalterCoin() {
	return this->WalterCoin;
}
double Wallet::getDogeCoin() {
	return this->DogeCoin;
}
Paypal* Wallet::getCuenta() {
	return this->cuenta;
}

