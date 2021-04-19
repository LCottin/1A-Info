#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//& renvoie l'adresse de la case
//* renvoie la valeur de la case

//returns the min and the max of the array
void min_max(int longueur, int tableau[], int* mini, int* maxi,char* choix) {
	for (int i=0;i<longueur;i++) {
		int valeur = tableau[i];
		if (valeur<*mini) {
			*mini = valeur;
		}
		else if (valeur>*maxi) {
			*maxi = valeur;
		}
	}
	if (strcmp(choix,"maxi") == 0) {
		mini = NULL;
	}
	if (strcmp(choix,"mini") == 0) {
		maxi = NULL;
	}
	//printf("%d\n",*mini);
	//printf("%d\n",*maxi);	
	
	return;
}


//------------------------------//
int main(int argc, char* argv[]) {
	int longueur = 5;
	int tableau[5] = {2,3,1,7,9};
	int mini = tableau[0];
	int maxi = tableau[0];

	min_max(longueur, tableau, &mini, &maxi,"mini");
	if (&mini) {
		printf("maxi = %d",maxi);
	}
	if (&maxi) {
		printf("mini = %d\n",mini);
	}

	return 0;
}
