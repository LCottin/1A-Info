#include <stdio.h>

//returns the sum of the array
int somme(int tab[], int n) {
	int i = 0;
	int total = 0;
	while (i<n) {
		total = total + tab[i];
		i++;
	}
	return total;
}

//returns the multiplication product of array1 and array2
int produit(int tab1[], int tab2[], int n) {
	int i = 0;
	int total = 0;
	while (i<n) {
		total = total + tab1[i]*tab2[i];
		i++;
	}
	return total;
}

	
//returns the array made of the sum between array1 and array2
void addition (int tab1[], int tab2[], int resultat[], int n) {
	int i = 0;
	while (i<n) {
		resultat[i] = tab1[i] + tab2[i];
		i++;
	}
	return;
}

/* prints a tab given in argment*/
int affiche(int tab[],int l){
	int i=0;
	while (i<l){
		printf("%d\n",tab[i]);
		i++;
	}

	return 0;
}




//------------------------------//
int main (int argc, char*argv[]) {
	int taille = 4;
	int tableau1[4] = {1,2,3,4};
	int tableau2[4] = {9,2,3,4};

	int s = somme(tableau1,taille);
	int p = produit(tableau1,tableau2,taille);

	int resultat[taille];
	addition(tableau1,tableau2,resultat,taille);
	affiche(resultat,taille);
	
	printf("\n%d\n",s);
	printf("%d\n",p);

	return 0;
}

