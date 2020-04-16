#include "Tonomat.h"
#include<fstream>
#include<iostream>
using namespace std;


Produs::Produs()
{

}

Produs::Produs(int cod, string nume, int pret)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
}

Produs::Produs(Produs const & t)
{
	this->cod = t.cod;
	this->nume = t.nume;
	this->pret = t.pret;
}

int Produs::getCod()
{
	return this->cod;
}

int Produs::getPret()
{
	return this->pret;
}

string Produs::getNume()
{
	return this->nume;
}

void Produs::setNmme(string s)
{
	this->nume = s;
}

void Produs::setPret(int pret)
{
	this->pret = pret;
}

void Produs::setCod(int cod)
{
	this->cod = cod;
}


Produs::~Produs()
{
}
ostream & operator<<(ostream & os, Produs & c) {
	os << c.cod << " " << c.nume << " " << c.pret;
	return os;
}
ifstream& operator>>(ifstream &is, Produs &c) {
	is >> c.cod >> c.nume>>c.pret;
	return is;
}

