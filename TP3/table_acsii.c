#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// prints ascii table
void afficher_ascii (int debut, int fin) {
	// \t makes a tabulation
	
	printf("\nCAR.\t dec.\t hexa.\t octal\n");
	
	for (int i=debut;i<=fin;i++) {
		printf("%c\t %d\t %x\t %o\n",i,i,i,i);
	}
	printf("\n");
	return;
}

//----------------------------//
int main(int argc, char* argv[]){
	int debut1 = atoi(argv[1]);
	int fin1 = atoi(argv[2]);

	afficher_ascii(debut1, fin1);
	
	return 0;
}	



