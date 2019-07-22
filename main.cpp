//exemplu supraincarcare
//Operatii cu matrici
#include "inc/matrici.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
	double **c;
	unsigned nlinii,ncoloane;	

	cout<<"Dati nr. de linii:";
	cin>>nlinii;

	cout<<"Dati nr. de coloane:";
	cin>>ncoloane;

	//alocam mem. pt. matricea c
	c=(double**)new double[nlinii];
	for(int i=0; i<nlinii; i++)
		c[i]=new double[ncoloane];

	srand(time(NULL));
	//initializare generare val. aleatoare

	//generare valori aleatoare pentru matrice
	for(int i=0; i<nlinii; i++)
		for(int j=0; j<ncoloane; j++)
			c[i][j] = rand()%10;

	Matrice X(nlinii,ncoloane,c), Y(nlinii,ncoloane,c);
	//matricile X si Y se initializeaza cu val. din mat. c

	Matrice S(nlinii,ncoloane), P(nlinii,ncoloane), T(nlinii,ncoloane);
	//matricile S, P si T se instantiaza cu constructorul implicit
	
	cout<<"\nDatele initiale:\n";
	X.afis('X');
	Y.afis('Y');

	//transpunem pe X in T
	T=T.transpunere(X);
	T.afis('T');

	//adunam X+Y	
	S = X + Y;
	S.afis('S');

	//inmultim X*Y
	P = X * Y;
	P.afis('P');

	return 0;
}
