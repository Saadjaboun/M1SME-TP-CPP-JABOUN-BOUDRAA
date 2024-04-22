#include <lcarte.h>
#include <iostream>
#include "lecteurcarte.h"
#include "baseclient.h"

using namespace std;

int numero, client;
int ok = 0;

void LecteurCarte::initialiser()
{
	initialisations_ports();
	//liberation_ports();
}

void LecteurCarte::lire_carte()
{
	BaseClient baseclient; 

	if(carte_inseree() != 1)
	{cout << "inserer une carte \n";}

	attente_insertion_carte();
	numero=lecture_numero_carte();
	cout << "numero lu: " << numero << "\n";

	if(carte_inseree())
	client= baseclient.Authentification(numero);
	//attente_retrait_carte();
}

int LecteurCarte::lire_carteAdmin()
{
	int AdminCard = 0;
	if(carte_inseree() != 1)
	{cout << "inserer la carte admin \n";}

	attente_insertion_carte();
	numero=lecture_numero_carte();
	cout << "numero lu: " << numero << "\n";

	if(numero == 8)
	AdminCard = 1;

	attente_retrait_carte();
	return AdminCard;
	
}

int LecteurCarte::CheckIfRegistredClient()
{
	return client;
}
int LecteurCarte::retrait_carte()
{
	BaseClient baseclient; 
	cout << "inserer une carte \n";
	attente_insertion_carte();
	numero=lecture_numero_carte();
	cout << "numero lu: " << numero << "\n";
	
	if(carte_inseree() /*&& voyants_disponibles*/)
	ok =baseclient.Retrait(numero,client);

	//liberation_ports(); 
	attente_retrait_carte();
	return ok;
}

