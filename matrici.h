#ifndef MATRICI_H
#define MATRICI_H

class Matrice
{
	double **a;
	int m,n;
public:
	Matrice(int, int);
	//primul constructor

	Matrice(int, int, double**);
	//al doilea constructor
	
	void set(int, int, double);
	//seteaza cu val elementul de pe pozitia (i,j)

	double get(int, int);
	//preia valoarea de pe pozitia (i,j)

	//preluarea nr-lui de linii
	int getM();

	//preluarea nr-lui de coloane	
	int getN();

	Matrice transpunere (Matrice &);
	//metoda transpunere matrice

	//Matrice inversare (Matrice &);
	//metoda inversare matrice

	friend Matrice operator+ (Matrice &, Matrice &);
	//operator adunare matrici

	friend Matrice operator* (Matrice &, Matrice &);
	//operator inmultire matrici

	void afis(char);
	//afisarea matricii

}; //închidere clasa Matrice

#endif //MATRICI_H
