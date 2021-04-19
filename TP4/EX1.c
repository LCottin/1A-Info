#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//& renvoie l'adresse de la case
//* renvoie la valeur de la case


//swaps two numbers
void swap(int* a, int* b) {
	//works on pointers NOT on numbers !!!!
	int temp = *b;	//temporary pointer
	*b = *a;
	*a = temp;
	return;
}


//sorts 'a' and 'b'
void order(int* a, int* b) { 
	if (*a>*b) {
		swap(a,b);
	}
	return;
}


//-------------------------//
int main(int argc, char* argv[]) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	//swap(&a,&b);		 //swaps pointers, not 'a' and 'b' ...
	//printf("%d, %d\n",a,b); 

	order(&a,&b);
	printf("%d, %d\n",a,b); 
	
	return 0;
}

