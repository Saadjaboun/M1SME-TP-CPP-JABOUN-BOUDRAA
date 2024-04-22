#include <iostream>
#include "memoire_borne.h"
#include "donnees_borne.h"
using namespace std;

#include "lecteurcarte.h"
#include "voyants.h"
#include "timer.h"
#include "recharge.h"
#include <lcarte.h>
#include "baseclient.h"

int stop ;
int code = 3;
int main()
{
	//io=acces_memoire(&shmid);

		LecteurCarte lecteurcarte;
	    	RECHARGE Recharge;
	    	VOYANTS Voyants;
		BaseClient Baseclient;
	    	Voyants.init();
	    	lecteurcarte.initialiser();

    	
	while(code > 2 || code < 1) 
	{
		cout << "choisir un mode : 1.Admin ou 2Client !\n";

		cin >> code; abs(code);
		if(code == 1)
		{	
			cout << "Bienvenue au mode admin !\n";
			if(lecteurcarte.lire_carteAdmin()==1)
			Baseclient.MakingVectors();
			else cout << "non admin !\n";
			code = 3;
		}
	    	if(code == 2)
		{

		    cout << "Bienvenue au mode client !\n";

		    while (1)
		    {
			lecteurcarte.lire_carte();
			if( lecteurcarte.CheckIfRegistredClient() >= 0)
			{
				Recharge.recharge();
				if(Recharge.DefaultBlinked() == 0) 
				{
					Recharge.charge();
					cout << "Charge Terminée !\n";

					do{		
					stop=lecteurcarte.retrait_carte();
					}while(stop==0);

					Recharge.recup();
					cout << "Fini !\n";
				}
			}
			else
			{
				cout << "Carte non enregistre !\n";
				cout << "rester en client : 2.oui !\n";
				cin >> code; abs(code);
				attente_retrait_carte();
				
				if(code == 2)
				attente_retrait_carte();
				else {break;}
			}
		    }
		    code = 3;
		}
	}
}
