#pragma once
#include"Service.h"
#include"Repo.h"
#include"Tonomat.h"
class UI
{
private:
	Service s;
public:
	UI();
	~UI();
	void run();
	void meniu();
	void add();
	void show();
	void delete_();
	void modificare();
	void buy();
	void rest(int suma,int pret,int &cinci, int &una);
	int find(int cod);
	void update(int cod, int modif);
	void update(int cod, string modif);
	int getPret(int cod);
};

