#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//returns 1 if mot is a palindromic word, 0 else
int est_palindrome(int n, char* mot) {
	int i = 0;
	int m = n/2;
	while (i<m+1) {
		if (mot[i] != mot[n-i-1]) {
		       return 0;
		}
		i++;
	}
	return 1;
}


//returns length of 'chaine'
int longueur_chaine(char* chaine) {
	int i = 0;
	while (chaine[i] != '\0') {
		i++;
	}
	return i;
}


//returns 1 if c is a letter of the alphabet, 0 else
int est_caractere(char c) {
	int x = c;
	if (x>= 65 && x<=90) {
		return 1;
	}
	if (x>= 97 && x<=122) {
		return 1;
	}
	return 0;
}

//transforms uppercase to lowercase
char maj_to_min(char c) {
	char l = c + 32;
	return l;
}


//---------------------------------------------------//
int main(int argc, char* argv[]) {
	int longueur = longueur_chaine(argv[1]);
	int pal1 = est_palindrome(longueur, argv[1]);

	printf("%d\n",pal1);
	//printf("%d\n",est_caractere(argv[2][0]));
	
	//printf("%c\n",maj_to_min(argv[3][0]));
			
	return 0;
}

