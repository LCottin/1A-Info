#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//returns length of 'chaine'
int longueur_chaine(char* chaine) {
	int i = 0;
	while (chaine[i] != '\0') {
		i++;
	}
	return i;
}


//returns the reversed chain
void chaine_miroir(char* chaine) {
	int l = longueur_chaine(chaine);
	for (int i=0;i<1+l/2;i++) {
		char temp = chaine[i]; //temp = temporary variable
		chaine[i] = chaine[l-i-1];
		chaine[l-i-1] = temp;
	}
	return;
}


//converts an integer into a string
void i_to_a(int nombre, char* chaine) {
	int i = 0;
	int negatif = nombre<0; //negatif = '1' if 'nombre' is negative
	if (negatif) {
		//makes a positive modulo if 'nombre' is negative
		nombre = -nombre;
	}
	while (nombre) {
		chaine[i] = nombre%10+'0';
		nombre = nombre/10;
		i++;
	}
	if (negatif) {
		//adds '-' at the beginning of the string
		chaine[i] = '-';
		i++; 
	}
	chaine[i] = 0; //adding 0 means end of the string
	chaine_miroir(chaine);
	return;
}




//-----------------------------//
int main(int argc, char* argv[]) {
	int valeur = atoi(argv[1]);

	//get the number of figures in 'valeur' to build the array
	int copie = atoi(argv[1]);
	int taille = 0;
	while (copie) {
		taille++;		
		copie = copie/10;
	}
	
	char ligne[taille];

	printf("%d\n",valeur);
	
	i_to_a(valeur,ligne);
	for (int i = 0;i<taille;i++) {
		printf("%c",ligne[i]);
	}
	printf("\n");
	return 0;
}
