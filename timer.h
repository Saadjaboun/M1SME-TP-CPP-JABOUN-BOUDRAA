#ifndef TIMER_H
#define TIMER_H

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <mem_sh.h>
#include<donnees.h>

class timer
{
  public : 
	entrees *io;int shmid;int depart_timer;
  public : 
	void timer_initialiser();
	int timer_valeur();
};


#endif
