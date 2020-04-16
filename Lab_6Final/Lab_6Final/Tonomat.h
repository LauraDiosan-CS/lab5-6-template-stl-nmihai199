#include<string>
#include<iostream>
using namespace std;
#pragma once
class Produs
{
private:
	string nume;
	int cod;
	int pret;
public:
	Produs();
	Produs(int cod, string nume, int pret);
	Produs(Produs const &t);
	int getCod();
	int getPret();
	string getNume();
	void setNmme(string s);
	void setPret(int pret);
	void setCod(int cod);
	~Produs();
	friend ostream& operator<<(ostream& os, Produs& c);
	friend ifstream& operator>>(ifstream &is, Produs &c);
};

