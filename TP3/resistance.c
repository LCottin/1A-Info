#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//returns 10^n
int times_pow10(n) {
	int puissance = 1;
	for (int i=0;i<n;i++) {
		puissance *= 10;
	}
	return puissance;
}

//returns the value of the resistance
//r = (c1*10+c2)*10^c3
int resistance(int c1, int c2, int c3) {
	return (c1*10+c2)*times_pow10(c3);
}


//returns the index of a string in an array of strings
int indice_of(char* element, char** chaine, int longueur) {
	int indice = 0;		//will be the index returned
	while(indice<longueur) {
		if (strcmp(element,chaine[indice]) == 0) {
			return indice;
		}
		indice++;
	}
	return -1;
}


//------------------------------------//
int main (int argc, char* argv[]) {
	enum couleurs {noir, marron, rouge, orange, jaune, vert, bleu, violet, gris, blanc};
	char* couleurs[10] = {"noir", "marron", "rouge", "orange", "jaune", 
			      "vert", "bleu", "violet", "gris", "blanc"};

	int color1 = indice_of(argv[1],couleurs,10);
	int color2 = indice_of(argv[2],couleurs,10);
	int color3 = indice_of(argv[3],couleurs,10);
	
	int r = resistance (color1,color2,color3);
	printf("%d\n",r);
	
	return 0;
}

