#pragma once
#include <iostream>
#include <string>
#include "Paypal.h"
using namespace std;
class Wallet
{
private:
	string nombreUsuario, password;
	Paypal* cuenta;
	double DogeCoin;
	int ethereum, WalterCoin;
public: 
	Wallet();
	Wallet(string, string, Paypal*);
	~Wallet();
	void comprar();
	void venta();
	void setNombreUsuario(string);
	void setContrasena(string);
	void setCuenta(Paypal*);
	void setDogeCoin(double);
	void setEthereum(int);
	void setWalterCoin(int);
	string getNombre();
	string getContrasena();
	Paypal* getCuenta();
	double getDogeCoin();
	int getEthereum();
	int getWalterCoin();
};