#include "UI.h"
#include<string>
#include<iostream>
#include"RepoFile.h"
#include"Monede.h"
using namespace std;


UI::UI()
{
}


UI::~UI()
{
}

void UI::run()
  
{
	this->meniu();
}
int menu()
{
	cout << endl;
	cout << "1.adaugare produs in Produs" << endl;
	cout<<"2.afisare produse din Produs" << endl;
	cout << "3.stergere produs unui produs " << endl;
	cout << "4.modificare produs unui produs" << endl;
	cout << "5.cumparare produs" << endl;
	cout << "0.exit" << endl;
	int op;
	cin >> op;
	return op;
}
void UI::meniu()
{
	
	int aux = 0;
	while (aux == 0)
	{
		int op = menu();
		switch (op)
		{
		case 1:
		{
			this->add();
			break;
		}
		case 2:
		{
			this->show();
			break;
		}
		case 3:
		{
			this->delete_();
			break;
		}
		case 4:
		{
			this->modificare();
			break;
		}
		case 5:
		{
			this->buy();
			break;
		}
		case 0:
		{
			aux = 1;
			break;
		}
		default:
		{
			cout << "optiune incorecta" << endl;
			break;
		}
		}
	}
}
void UI::add()
{
	cout << "introduceti codul produsului  :";
	int cod;
	cin >> cod;
	if(this->find(cod)!=-1)
	{
		cout << "codul exista deja in baza de date" << endl;
	}
	else
	{
		cout << "introduceti numele produsului  :";
		string nume;
		cin >> nume;
		cout << "introduceti pretul produsului  :";
		int pret;
		cin >> pret;
		Produs t(cod, nume, pret);
		this->s.add(t);
	}


}

void UI::show()
{
	cout << "--------------------------------" << endl;
	for (int i = 0; i < s.getSize(); i++)
	{
		cout << s.getAll().getElem()[i].getCod() << " " << s.getAll().getElem()[i].getNume() << " " << s.getAll().getElem()[i].getPret() << endl;
	}
	cout << "--------------------------------"<<endl;
}

void UI::delete_()
{
	cout << endl;
	cout << "introduceti codul produsului pe care doriti sa-l stergeti :";
	int cod;
	cin >> cod;
	int poz = 0;
	poz=this->find(cod);
	if (poz == -1)
	{
		cout << "Codul introdus nu se afla in Tonomat" << endl;

	}
	else {
		cout << "Stergere cu succes !"<<endl;
		this->s.del(poz);
	}
}

void UI::modificare()
{
	cout << "introduceti codul produsului :";
	int cod;
	cin >> cod;
	cout << endl;
	cout << "1.modificare nume " << endl;
	cout << "2.modificare pret " << endl;
	int op;
	cin >> op;
	cout << endl;
	string nume;
	int pret;
	switch (op)
	{
	case 1:
	{
		cout << "introduceti noul nume  : ";
		cin >> nume;
		this->update(cod, nume);
		break;
	}
	case 2:
	{
		cout << " introduceti noul pret  :";
		cin >> pret;
		this->update(cod, pret);
		
		break;
	}
	default:
	{
		cout << "optiune invalida" << endl;
		break;
	}
	}
}

void UI::buy()
{
	
	cout << "introduceti codul produsului  :";
	int cod;
	cin >> cod;
	int pret = this->getPret(cod);
	int find = this->find(cod);
	if (find == -1)
	{
		cout << "cod invalid!!!" << endl;
	}
	else
	{
		cout << "pretul produsului este  " << pret << " lei : " << endl;
		cout << "introduceti suma de bani : ";
		int suma_introdusa;
		cin >> suma_introdusa;
		if (suma_introdusa < pret)
		{
			cout << endl;
			cout << "Ati introdus prea putini bani " << endl;

		}
		else if (suma_introdusa == pret)
		{
			cout << endl;
			cout << "Tranzactie reusita! " << endl;
			cout << "La revedere!!!";
		}
		else
		{
			cout << endl;
			cout << "se verifica daca automatu are sa va dea rest " << endl;
			cout << "----------------------------------------------------------------" << endl;
			int cincizeci, zece;
			this->rest(suma_introdusa,pret, cincizeci, zece);
			cout << "Restul  : " << cincizeci << " de monede de 50 de bani" << "  " << zece << "  de monede de 10 bani"<<endl;
			cout << "----------------------------------------------------------------" << endl;
		}
	}

}

void UI::rest(int suma, int pret,int & cinci, int & una)
{
	int aux;
	aux = suma - pret;
	aux = aux * 10;
	cinci = aux / 5;
	una = aux - (cinci * 5);
}

int UI::find(int cod)
{
	for (int i = 0; i < s.getSize(); i++)
	{
		if(cod==s.getAll().getElem()[i].getCod())
		{
			return i;
		}
	}
	return -1;
}

void UI::update(int cod, int modif)
{
	//modificare pret
	Produs t;
	t.setCod(cod);
	t.setPret(modif);
	for (int i = 0; i < s.getSize(); i++)
	{
		if(this->s.getAll().getElem()[i].getCod()==cod)
		
		{
			t.setNmme(s.getAll().getElem()[i].getNume());
			this->s.update(i,t);
			break;

		}
	}
}

void UI::update(int cod, string modif)
{
	Produs t;
	t.setCod(cod);
	t.setNmme(modif);
	for (int i = 0; i < s.getSize(); i++)
	{
		if (cod == s.getAll().getElem()[i].getCod())
		{
			t.setPret(s.getAll().getElem()[i].getPret());
			this->s.update(i, t);
			break;

		}
	}
}

int UI::getPret(int cod)
{
	
		for (int i = 0; i < s.getSize(); i++)
		{
			if (cod == s.getAll().getElem()[i].getCod())
			{
				return s.getAll().getElem()[i].getPret();
			}
		}
		return -1;
	
}


