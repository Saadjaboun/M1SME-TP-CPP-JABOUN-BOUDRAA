#include"timer.h"
#include <iostream>
using namespace std;


void timer::timer_initialiser()
{
	io=acces_memoire(&shmid);
	/* associe la zone de memoire partagee au pointeur */
	if (io==NULL) cout << "Erreur pas de mem sh\n";
	depart_timer=io->timer_sec;
}

int timer::timer_valeur(){
	int temps=io->timer_sec-depart_timer;
	return temps;
}

