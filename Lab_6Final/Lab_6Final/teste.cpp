#include "teste.h"
#include"Tonomat.h"
#include"Repo.h"
#include"UI.h"
#include"RepoFile.h"
#include"Service.h"
#include<cassert>

void teste_ProdusGetandSet()
{
	Produs t(1, "coca", 10);
	assert(t.getNume() == "coca"&&t.getPret() == 10 && t.getCod() == 1);
	t.setCod(14);
	t.setPret(100);
	t.setNmme("coca-cola");
	assert(t.getNume() == "coca-cola"&&t.getPret() == 100 && t.getCod() == 14);

}

void testeRepoAdd()
{
	Repo<Produs> r;
	Produs t;
	t.setCod(1);
	t.setNmme("cola");
	t.setPret(10);
	r.addElem(t);
	
	assert(r.getElem()[0].getCod() == 1&&r.getElem()[0].getNume()=="cola"&&r.getElem()[0].getPret()==10);
	

}
void testeRepoDelete()
{
	Repo<Produs> r;
	Produs t;
	t.setCod(1);
	t.setNmme("cola");
	t.setPret(10);
	r.addElem(t);
	t.setCod(2);
	r.addElem(t);
	r.delet(1);
	assert(r.getElem()[0].getCod() == 1);
}
void testeRepoUpdate()
{
	Repo<Produs> r;
	Produs t;
	t.setCod(1);
	t.setNmme("cola");
	t.setPret(10);
	r.addElem(t);
	Produs t2;
	t2.setCod(2);
	t2.setNmme("cola");
	t2.setPret(10);
	r.addElem(t2);
	r.modif(0, t2);
	assert(r.getElem()[0].getCod() == 2);
}
void testeRest()
{
	UI u;
	int cinci, unu;
	u.rest(11, 10, cinci, unu);
	assert(cinci == 2 && unu == 0);

}
void teste_RepoFile()
{
	RepoFile<Produs > rf;
	rf.setFileName("Tonomat.txt");
	assert(rf.getFileName() == "Tonomat.txt");
	
}

void testeServiceAdd()
{
	Service s;
	Produs t;
	t.setCod(1);
	t.setNmme("cola");
	t.setPret(10);
	s.add(t);
	assert(s.getAll().getElem()[0].getCod() == 1 && s.getAll().getElem()[0].getPret() == 10);
}
void testeServiceUpdate()
{

	Service s;
	Produs t;
	t.setCod(1);
	t.setNmme("cola");
	t.setPret(10);
	s.add(t);
	Produs m;
	m.setPret(10000);
	m.setCod(100);
	s.update(0, m);
	assert(s.getAll().getElem()[0].getPret() == 10000 && s.getAll().getElem()[0].getCod()==100);
	
	
}
void testeServiceDelete()
{
	Produs t;
	t.setCod(1);
	t.setNmme("cola");
	t.setPret(10);
	Service s;
	s.add(t);
	s.del(0);
	assert(s.getSize() == 0);
}

void teste()
{
	 teste_ProdusGetandSet();
	 testeRepoAdd();
	 testeRepoDelete();
	 testeRepoUpdate();
	 teste_RepoFile();
	 testeServiceAdd();
	testeServiceUpdate();
	testeServiceDelete();
	testeRest();
}
