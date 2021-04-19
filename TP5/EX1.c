#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//& renvoie l'adresse de la case
//* renvoie la valeur de la case

//returns the min and the max of the array
void min_max(int longueur, int tableau[], int* mini, int* maxi) {
	for (int i=0;i<longueur;i++) {
		int valeur = tableau[i];
		if (valeur<*mini) {
			*mini = valeur;
		}
		else if (valeur>*maxi) {
			*maxi = valeur;
		}
	}
	return;
}


//---------------------------//
int main(int argc, char* argv[]) {
	int longueur = 10;
	int tableau[10] = {27,429,204,5,22,6,8,9,0};
	int mini = tableau[0];
	int maxi = tableau[0];
	
	min_max(longueur, tableau, &mini, &maxi);
	printf("mini = %d, maxi = %d\n",mini,maxi);
	return 0;
}
