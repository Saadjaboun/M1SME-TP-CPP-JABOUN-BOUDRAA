#ifndef RECHARGE_H
#define RECHARGE_H

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <mem_sh.h>
#include <iostream>

/*entrees *io;
int shmid;*/

class RECHARGE
{

  public : 
	entrees *io;int shmid;
  public : 
	void recharge();
	void charge();
	void recup();
	int DefaultBlinked();
};


#endif


