#include <stdio.h>

/* prints a tab given in argment*/
int affiche(int tab[],int l){
	int i=0;
	while (i<l){
		printf("%d\n",tab[i]);
		i++;
	}

	return 0;
}


//returns 1 if a is even, else 0
int pair(int a){
	if (a%2 == 0) {
		return 1;
	}
	return 0;
}



//fills an array with n first even numbers
void tableau_pair (int tab[],int n) {

	int i=0;
	int l;
	int parité = pair(n);
	if (parité == 1){
		l= n/2;
	}
	else {
		l = (n+1)/2;
	}
	while (i<l+1) {
		tab [i] = 2*i;
		i++;
	}
	return;
}



//-------------------------------------//
int main (int argc, char*argv[]) {
	int taille = 50;
	int test[taille];

	tableau_pair(test,taille);

	affiche(test, taille/2);
	
	return 0;

}
	
