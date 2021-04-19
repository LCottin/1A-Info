#include <stdio.h>

//returns '1' if the array is sorted, '0' else
int est_trie(int tab[], int n) {
	int i = 0;
	while (i<n-1) {
		if (tab[i] > tab[i+1]) {
			return 0;
		}
		i++;
	}
	return 1;
}


//returns '1' is a is in the array, '0' else
int recherche (int tab[], int a, int n) {
	int i = 0;
	while(i<n) {
		if (a==tab[i]) {
			return 1;
		}
		i++;
	}
	return 0;
}


//same as previous fonction but uses dichotomy
int dichotomie_iterative (int tab[], int x, int n) {
	int a = 0;
	int b = n-1;
	while (a < b) {
		int milieu = (a+b)/2;
		
		if (tab[milieu] == x) {
			return 1;
		}
		if (tab[milieu] < x) {
			a = milieu+1;
		}
		else {
			b = milieu-1;
		}
	}
	return 0;
}


int dichotomie_recursive(int tab[], int x, int gauche, int droite) {
	int milieu = (gauche+droite)/2;

	if (x<tab[milieu]) {
		return dichotomie_recursive(tab,x,gauche,milieu-1);		
	}
	else if (tab[milieu] < x) {
		return dichotomie_recursive(tab,x,milieu+1,droite);		
	}
	return 1;
}


//----------------------------------------//
int main (int argc, char*argv[]) {
	int tableau1[5] = {1,2,3,3,4};
	int tableau2[5] = {1,2,5,7,3};

	int t1 = est_trie(tableau1,5);
	int t2 = est_trie(tableau2,5);

	int presence1 = recherche (tableau1,4,5);
	int presence2 = dichotomie_iterative (tableau1,4,5);
	int presence3 = dichotomie_recursive(tableau1,4,0,5);
//	printf("%d\n",t1);
//	printf("%d\n",t2);
//	printf("%d\n",presence1);
//	printf("%d\n",presence2);
	printf("%d\n",presence3);

	return 0;
}

