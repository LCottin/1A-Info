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
		char temp = chaine[i];
		chaine[i] = chaine[l-i-1];
		chaine[l-i-1] = temp;
	}
	return;
}

//returns the reversed chain without destroying it
void chaine_miroir2(char* chaine,char* chaine2) {
	int l = longueur_chaine(chaine);
	for (int i=0;i<=l;i++) {
		chaine2[i] = chaine[l-i-1];
	}
	return;
}


//---------------------------------//
int main(int argc, char* argv[]) {
	char* ligne = argv[1];
	int l = longueur_chaine(ligne);
	char* ligne2 = "BONJOUR";

	printf("%s\n",ligne);
	chaine_miroir2(ligne,ligne2);
	printf("%s\n",ligne2);

	return 0;
}

