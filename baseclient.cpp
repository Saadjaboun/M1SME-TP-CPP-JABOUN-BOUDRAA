#include <donnees_borne.h>
#include "baseclient.h"
#include <iostream>
#include <vector>

using namespace std;
vector<int> NumID, PWD;
int Taille;

void BaseClient::MakingVectors()
{
	cout << "choisir le nombre de client a ajouter actuellement il y'en a " << NumID.size() << ": !\n";	
	cin >> Taille;
	int inserer = 0;

	for(int startI = 0; startI < Taille; startI++)
	{
		/*cout << "entrée l'id de la " <<startI + 1<< "eme carte : !\n";
		cin >> inserer;*/
		/*while(inserer == 4)
		{
			cout << "carte déja prise entrée une autre : !\n";
			cin >> inserer;
		}*/
		int ResterEnLoop = 1; int taille2 = NumID.size();int startI2 = 0;
		//cout << "entrée l'id de la " <<startI + 1<< " eme carte : !\n";
		while(ResterEnLoop != 0)
		{
			cout << "entrée l'id de la " <<startI + 1<< "eme carte : !\n";
			cin >> inserer;

			for(startI2 = 0; startI2 < taille2; startI2++)
			{
				if(inserer == NumID[startI2])
				break;
				else if(inserer == 8)
				break;
			}
			if(startI2 >= taille2 && inserer != 8)
			ResterEnLoop =0;
		}
		

		NumID.push_back(inserer);

		cout << "entrée son mot de passe : !\n";
		cin >> inserer;
		PWD.push_back(inserer);
	}
}	

int BaseClient::Authentification(int numcarte)
{
	int code;
	int numclient=-10;
	int flag=0;

	//int tab[2][2];
	int i,j;

	/*tab[0][0]=8;
	tab[0][1]=88;

	tab[1][0]=32;
	tab[1][1]=3232;*/


	
	for(j=0;j<Taille;j++){
		
		if(NumID[j]==numcarte)
			numclient=j;
	}

	if (numcarte==NumID[numclient]){
	
	for(i=0;i<3;i++){
		cout << "Bienvenue client" << NumID[numclient] << " ! Entrez votre code: \n";
		cin >> code;

		
		if (code == PWD[numclient])
		{
			cout << "Code bon !\n";
			flag = 1;
			i=3;
		}
		else {
				cout << "Code faux ! \n";
				cout << "Il vous reste " << (2-i) << "essais! \n";
		}
		
	}


		if(flag==1)
			cout << "retirer votre carte \n";
		else{
		//printf("Blink def\n");
		cout << "Mauvais code 3fois retirer votre carte \n";
		/*clignoteDefault(ROUGE);//Mauvais code 3x*/
		numclient=-10;
		}

	}

	return numclient;
}

int BaseClient::Retrait(int numcarte, int numclient)
{
	int code = 0;

	//int tab[2][2];
	int i,right=1;

	/*tab[0][0]=8;
	tab[0][1]=88;

	tab[1][0]=32;
	tab[1][1]=3232;*/


	if (numcarte==NumID[numclient])
	{
	
		for(i=0;i<3;i++)
		{
			cout << "Entrez votre code client: \n";
			cin >> code;
		
			if (code == PWD[numclient])
			{
				cout <<"le Code est bon !\n";right = 1;
				i=3;
			}
			else 
			{
					cout << "le Code est faux ! \n";
					cout << "Il vous reste " <<(2-i)<< " essais! \n";
					right = 0;
			}
		
		}

	}
	else
	{
		cout <<"faux client\n";
		 right = 0;
		//clignoteDefault(ROUGE);
	}


	return right;
}

