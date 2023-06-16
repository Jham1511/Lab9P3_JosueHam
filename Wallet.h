#pragma once
#include <iostream>
#include <string>
#include "Paypal.h"
using namespace std;
class Wallet
{
private:
	string nombreUsuario, password;
	Paypal cuenta;
	double DogeCoin;
	int ethereum, WalterCoin;
public: 
	void comprar();
	void venta();
};