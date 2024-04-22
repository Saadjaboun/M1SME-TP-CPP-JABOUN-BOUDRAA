#ifndef VOYANTS_H
#define VOYANTS_H

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <mem_sh.h>
#include <iostream>

/*entrees *io;
int shmid;*/
class VOYANTS
{

  public : 
	entrees *io;int shmid;
  public : 
	void clignoteDefault(led couleur);
	void eteindreDispo(led couleur);
	void allumerCharge(led couleur);
	void allumerTrappe(led couleur);
	void allumerDispo(led couleur);
	void clignoteCharge(led couleur);
	void init();
	void eteindreTrappe(led couleur);
	void allumerPrise(led couleur);
};


#endif
