#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fills an array with '0'
void array_zero(char* tableau, int nb_octet) {
	for (int i=0;i<nb_octet*8;i++) {
		*tableau++ = 0;
	}
	return;
}


//------------------------------//
int main (int argc, char* argv[]) {
	char tab[32];
	int nb_octet = 4;
	array_zero(tab,nb_octet);
	
	for (int i=0;i<32;i++) {
		printf("%d\n",tab[i]);
	}
	return 0;
}
