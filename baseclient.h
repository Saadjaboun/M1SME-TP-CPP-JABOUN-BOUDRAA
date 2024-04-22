#ifndef BASECLIENT_H
#define BASECLIENT_H


class BaseClient
{
  public : 
	int Authentification(int numcarte);
	int Retrait(int numcarte, int numclient);
	void MakingVectors();
};

#endif // BASECLIENT_H
