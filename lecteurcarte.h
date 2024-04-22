#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>


class LecteurCarte
{
  public : 
	void initialiser();
	void lire_carte();
	int lire_carteAdmin();
	int retrait_carte();
	int CheckIfRegistredClient();
};

#endif // LECTEURCARTE_H
