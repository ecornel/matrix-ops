#include <iostream>
#include "matrici.h"

using namespace std;

//definim metodele din cadrul clasei Matrice

//primul constructor
Matrice::Matrice(int m1, int n1)
{
	m=m1;
	n=n1;
	
	//alocare memorie pentru matrice
	a=(double**)new double[m];
	for(int i=0; i<m; i++)
		a[i]=new double[n];

	//initializarea matricii
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			a[i][j]=0;
}

//al doilea constructor
//preia valori din alta matrice
Matrice::Matrice(int m1, int n1, double **a1)
{
	m=m1;
	n=n1;
	
	a=(double**)new double[m];
	for(int i=0; i<m; i++)
		a[i]=new double[n];

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			a[i][j]=a1[i][j];
}

//se aplica principiul încapsularii datelor
//datele membre vor fi referite numai prin metode publice
void Matrice::set(int i, int j, double val)
{
	a[i][j]=val;
}

double Matrice::get(int i,int j)
{
	return a[i][j];
}

//preluarea nr-lui de linii
int Matrice:: getM(){
	return m;
}

//preluarea nr-lui de coloane
int Matrice::getN(){
	return n;
}

//metoda de transpunere
Matrice Matrice::transpunere (Matrice &A){
	Matrice C(A.getM(), A.getN());

	for(int i=0; i<A.getM(); i++)
		for(int j=0; j<A.getN(); j++)
			C.set(i,j, A.get(j,i));
	
	return C;
}

//operatorul de adunare matrici
Matrice operator+(Matrice &A, Matrice &B)
{
	Matrice C(A.getM(), A.getN());

	//presupunem respectarea dimensiunilor
	for(int i=0; i<A.getM(); i++)
		for(int j=0; j<A.getN(); j++)
			C.set(i,j, A.get(i,j)+B.get(i,j));

	return C;
}

//operatorul de inmultire matrici
Matrice operator*(Matrice &A, Matrice &B)
{
	Matrice C(A.getM(), B.getN());
	int i,j,k;

	if (A.getM() == B.getN()){
		for(i=0; i<A.getM(); i++){
			for(j=0; j<A.getN(); j++){
				C.set(i,j,0);
					for(k=0; k<A.getM(); k++)
						C.set(i,j, C.get(i,j)+A.get(i,k)*B.get(k,j));
			}
		}
	}
	else
		cout << "\nEroare: matricile nu se pot inmulti!!!\n";

	return C;
}

//metoda de afisare a matricii
void Matrice::afis(char ch)
{
	cout<<"\nMatricea " << ch <<" : \n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}



