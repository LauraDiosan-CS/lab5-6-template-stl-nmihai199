#include "Repo.h"
#include"Monede.h"

#include <iostream>
#include <fstream>

#include <string>
using namespace std;
template <class T>
class RepoFile : public Repo<T>
{
private:
	ifstream in;
	ofstream of;
	string fileName;
public:
	RepoFile() : Repo<T>() {};
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);
	void addElement(int nr);
	string getFileName();

	const RepoFile<T>& operator=(const RepoFile<T>& r)
	{
		this->in = r.in;
		this->fileName = r.fileName;
		return *this;
	}


};

template <class T>
RepoFile<T>::RepoFile(string fileName) {
	this->fileName = fileName;
	in.open(fileName);
	if (!in) {
		cerr << "The file could not be open!" << endl;
	}
	int nr;
	addElement(nr);
}
template <class T>
RepoFile<T>::~RepoFile(){
	in.close();
	of.close();
};


template <class T>
void RepoFile<T>::setFileName(string fileName)
{
	this->fileName = fileName;
	in.open(fileName);
	if (!in) {
		cerr << "The file could not be open!" << endl;
	}
}

template <class T>
void RepoFile<T>:: addElement ( int nr) 
{
	T el;
	string fis;
	nr = 0;
	while (in >> el) {

		Repo<T>::addElem(el);
	}
}

template<class T>
string RepoFile<T>::getFileName()
{
	return this->fileName;
}
