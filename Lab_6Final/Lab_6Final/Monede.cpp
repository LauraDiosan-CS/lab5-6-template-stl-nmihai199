#include "Monede.h"
#include<fstream>
#include<iostream>
using namespace std;
Monede::Monede()
{
	this->nr = 0;
	this->val = 0;
}

Monede::Monede(double val, int nr)
{
	this->nr = nr;
	this->val=val;
}

Monede::~Monede()
{

}

double Monede::getVal()
{
	return 0.0;
}

int Monede::getNr()
{
	return this->nr;
}

void Monede::setNr(int nr)
{
	this->nr = nr;
}

void Monede::setVal(double valoare)
{
	this->val = valoare;
}

ostream & operator<<(ostream & os, Monede & c) {
	os << c.getVal() << " " << c.getNr() << endl;
	return os;
}
ifstream& operator>>(ifstream &is, Monede &c) {
	is >> c.nr >> c.val;
	return is;
}

