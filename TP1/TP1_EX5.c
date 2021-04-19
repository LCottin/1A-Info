#include <stdio.h>

//returns line n of Pascal's triangle
void pascal_ligne(int n, int valeurs[]) {
	int i = n-1;
	valeurs[i] = 1;
	while (i-1>0) {
		i = i-1;
		valeurs[i] = valeurs[i]+valeurs[i-1];
	}
}


//prints n first lines of Pascal's triangle
void pascal(int n) {
	int i = 1;
	int tab[n];
	while (i<n) {
		pascal_ligne(i,tab);

		//prints each line of the array
		int k = 0;
			while (k<i) {
				printf("%d",tab[k]);
				k++;
				//printf("-");
				
			}
		printf("\n");
		i++;
	}
}


//---------------------------------------//
int main(int argc, char* argv[]) {
	//int tableau[10] = {1,2,3,4,5,6,7,8,9,0};
	
	pascal(17);
	return 0;
}

