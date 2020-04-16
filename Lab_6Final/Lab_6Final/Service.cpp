#include "Service.h"
#include<iostream>
#include<vector>
using namespace std;


Service::Service()
{
}


Service::~Service()
{
}

void Service::add(Produs & t)
{
	this->s.addElem(t);
}

Repo<Produs> Service::getAll()
{
	return this->s;
}

int Service::getSize()
{
	return this->s.getSize();
}


void Service::del(int poz)
{
	
	this->s.delet(poz);
}


void Service::update(int poz, Produs & p)
{
	this->s.modif(poz, p);
}


