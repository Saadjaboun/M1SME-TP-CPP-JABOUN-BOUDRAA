#include "voyants.h"
#include "timer.h"

#include <memoire_borne.h>
#include<donnees_borne.h>
#include <mem_sh.h>
#include<donnees.h>
#include <unistd.h>
#include <iostream>

/*entrees *io;
int shmid;*/
using namespace std;

void VOYANTS::init(){
	io = acces_memoire(&shmid);
}
void VOYANTS::clignoteDefault(led couleur){	
	int i;	
	io = acces_memoire(&shmid);	
	for(i=0;i<4;i++){
	io-> led_defaut=couleur;
	sleep(1);
	io->led_defaut=OFF;
	sleep(1);
	}
}

void VOYANTS::clignoteCharge(led couleur){	
	int i;	
	io = acces_memoire(&shmid);
	for(i=0;i<4;i++){
	io-> led_charge=couleur;
	sleep(1);
	io->led_charge=OFF;
	sleep(1);
	}
}

void VOYANTS::eteindreDispo(led couleur){
	io = acces_memoire(&shmid);
	io->led_dispo=OFF;
}

void VOYANTS::allumerCharge(led couleur){
	io = acces_memoire(&shmid);
	io-> led_charge=couleur;
}

void VOYANTS::allumerTrappe(led couleur){
	io = acces_memoire(&shmid);
	io-> led_trappe=couleur;
}

void VOYANTS::allumerDispo(led couleur){
	io = acces_memoire(&shmid);
	io-> led_dispo=couleur;
}
void VOYANTS::eteindreTrappe(led couleur){
	io = acces_memoire(&shmid);
	io-> led_trappe=couleur;
}
void VOYANTS::allumerPrise(led couleur){
	io = acces_memoire(&shmid);
	io-> led_prise=couleur;
}
