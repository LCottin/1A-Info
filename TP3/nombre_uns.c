#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//gives the amount of '1' in 'nombre' ...

//...uses mask
int compte_bits_1(int nombre) {
	clock_t start = clock(); //starts the clock
	int longueur = sizeof(nombre)*8; 
	int compteur = 0;

	for (int i = 0;i<longueur;i++) {
		//compares each bit of 'nombre' and (1<<i)
		// if i = 11101 then 1<<i = 11010
		if (nombre & (1<<i)) { 
			compteur++;
		}
	}

	clock_t end = clock(); //ends the clock
	int duree = end-start; //programm duration


	printf("Duree d'execution : %d ms.\n",duree);
	return compteur;
}

//...uses the number
int compte_bits_2(int nombre) {
	clock_t start = clock(); //starts the clock	
	int compteur = 0;
	int longueur = sizeof(nombre)*8; 	
	while (nombre) {
		//if the last bit is 1
		if (nombre & 1) {
			compteur ++;
		}
		// if i = 11101 then i>>1 = 01110
		nombre = nombre>>1;
	}

	clock_t end = clock(); //ends the clock
	int duree = end-start; //programm duration 
	printf("Duree d'execution : %d ms. \n",duree);
	return compteur;
}


//uses hackers delight's method
int hackers (int nombre) {
	clock_t start = clock(); //starts the clock	
	int compteur = 0;
	
	while (nombre !=0) {
		int cebit = nombre & (~nombre+1);
		nombre = nombre^cebit;
		compteur ++;
	}
	clock_t end = clock(); //ends the clock
	int duree = end-start; //rogramm duration

	printf("Duree d'execution : %d ms. \n",duree);

	return compteur; 
}
	

//----------------------------------//
int main (int argc, char* argv[]) {
	int n = compte_bits_1(atoi(argv[1]));
	int n2 = compte_bits_2(atoi(argv[1]));
	int n3 = hackers(atoi(argv[1]));

	printf("%d\n",n);
	printf("%d\n",n2);
	printf("%d\n",n3);

	return 0;
}
