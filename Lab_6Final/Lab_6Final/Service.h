#pragma once
#include"Repo.h"
#include"Monede.h"
#include"Tonomat.h"
#include<string>
#include<iostream>
using namespace std;
class Service
{
private:
	Repo<Produs> s;
	//RepoFile<Produs> rp;
public:
	Service();
	~Service();
	void add(Produs  &t );
	Repo<Produs> getAll();
	int getSize();
	void del(int poz);
	void update(int poz, Produs &p);
	int getPret(int cod);

};

