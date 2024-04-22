
#include <unistd.h>
#include <lcarte.h>

#include <iostream>
#include "memoire_borne.h"
#include "donnees_borne.h"

#include <mem_sh.h>
#include <donnees.h>

#include "timer.h"
#include "recharge.h"
#include "voyants.h"

using namespace std;

int timee,i;
int Default_Blinked = 0;


void RECHARGE::recharge()
{
	timer Timer;
	io=acces_memoire(&shmid);
	VOYANTS Voyants;

	//io=acces_memoire(&shmid); //Accès mémoire
	attente_retrait_carte(); //attente retrait carte

	Voyants.clignoteCharge(VERT);

	Timer.timer_initialiser();
	timee=Timer.timer_valeur();
	while (io->bouton_charge!=1 || timee>=10){
	timee=Timer.timer_valeur();
	if(timee>=10)break;
	}
	if(timee<10){
		Voyants.eteindreDispo(OFF); //Gestion des LEDS
		Voyants.allumerCharge(ROUGE);
		Voyants.allumerTrappe(VERT);
		io->gene_pwm=DC; //io->gene_u=12;
		Default_Blinked = 0;
	}
	else{
		Voyants.allumerDispo(VERT);
		Voyants.clignoteDefault(ROUGE);
		Default_Blinked = 1;
	}
}
int RECHARGE::DefaultBlinked()
{
	return Default_Blinked;	
}

void RECHARGE::charge(){
	io=acces_memoire(&shmid);
	VOYANTS Voyants;

	while((io->gene_u)!=9)
	usleep(1000);// Processeur trop rapide donc on met des sleep 
	Voyants.eteindreTrappe(OFF);
	Voyants.allumerPrise(VERT);
	sleep(1);
	io->gene_pwm=AC_1K;
	sleep(1);
	//io->gene_u=6;
	sleep(1);
	io->contacteur_AC=1;
	io->gene_pwm=AC_CL;

	sleep(1);

	while((io->gene_u)!=9){
		sleep(1);
		cout << "En charge...\n";
		if(io->bouton_stop==1)
		io->gene_u=9;
	}

	io->contacteur_AC=0;
	io->gene_pwm=DC;
	io->gene_u=9;
	Voyants.allumerCharge(VERT);

}

void RECHARGE::recup(){
	io=acces_memoire(&shmid);
	VOYANTS Voyants; 

	Voyants.allumerTrappe(VERT);

	while((io->gene_u)!=12)
	usleep(1000);// proco trop rapide; 
	cout << "Vroum Vroum\n";
	Voyants.eteindreTrappe(OFF);
	Voyants.allumerPrise(OFF);
	Voyants.allumerCharge(OFF);
	Voyants.allumerDispo(VERT);
}
