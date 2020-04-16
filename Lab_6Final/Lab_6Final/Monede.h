#pragma once
#include <iostream>
using namespace std;


class Monede
{
private:
	double val;
	int nr;
public:
	Monede();
	Monede(double val, int nr);
	~Monede();
	double getVal();
	int getNr();
	void setNr(int nr);
	void setVal(double valoare);
	friend ostream& operator<<(ostream& os, Monede& c);
	friend ifstream& operator>>(ifstream &is, Monede &c);
};