#pragma once
#include"Monede.h"
#include<vector>
#include<iostream>
using namespace std;
template <class T>
class Repo
{
protected:
	vector<T> v;
	
public:
	Repo();
	~Repo();
	void addElem(T e);
	vector<T> getElem();
	int getSize();
	void delet(int i);
	void modif(int poz,T e);
	
};

template<class T>
 Repo<T>::Repo()
{
}

template<class T>
 Repo<T>::~Repo()
{
}

 template<class T>
 void Repo<T>::addElem(T e)
 {
	 this->v.push_back(e);
 }

 template<class T>
 vector<T> Repo<T>::getElem()
 {
	 return this->v;
 }

 template<class T>
  int Repo<T>::getSize()
 {
	 return this->v.size();
 }

  template<class T>
  void Repo<T>::delet(int poz)
  {
	if(poz>-1&& poz<v.size())
	 v.erase(v.begin() + poz);
  }

  template<class T>
   void Repo<T>::modif(int poz, T e)
  {
	   for (int i = 0; i < v.size(); i++)
	   {
		   if (i == poz)
		   {
			   v[i] = e;
		   }
	   }
  }

 

 
 

 

