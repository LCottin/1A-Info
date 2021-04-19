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

int nombre_voyelle(char* chaine) {
	int i = 0;
	int v = 0;
	while (chaine[i] != '\0') {
		switch(chaine[i]) {
			case 'a': 
				v++;
				break;
			case 'e' :
				v++;
				break;
			case 'i' :
				v++;
				break;
			case 'o' :
				v++;
				break;
			case 'u' :
				v++;
				break;
			case 'y' :
				v++;
				break;
		}
		i++;
	}
	return v;
}



//--------------------------------//
int main(int argc, char* argv[]){
	int l1 = longueur_chaine(argv[1]);
	
	//strlen = returns length of the string 
	//included in <stdio.h>
	int l2 = strlen(argv[2]);

	printf("%d\n",l1);
	printf("%d\n",l2);

	//strcmp(l1,l2) : return 0 if l& = l2
	printf("%d\n",strcmp(argv[1],argv[2]));
	
	int v = nombre_voyelle(argv[1]);
	printf("%d\n", v);
	
	return 0;
}
