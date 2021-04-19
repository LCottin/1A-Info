#include <stdio.h>
#include <stdlib.h>

//Fibonnaci's recursive series
int fibonnaci_recursive(int n) {
	if (n<=1) {
		//returns '0' if n=0, '1' if n=1
		return n; 
	}
	return fibonnaci_recursive(n-1)+fibonnaci_recursive(n-2);
}


//Fibonnaci's iterative series
int fibonnaci_iterative(int n) {
	if (n<=1) {
		return n;
	}

	int valeurs[n];
	int i = 2;
	valeurs[0] = 0;
	valeurs[1] = 1;

	while (i<n+1) {
		valeurs[i] = valeurs[i-1]+valeurs[i-2];
		i++;
	}
	return valeurs[n];
}


//---------------------------------//
int main(int argc, char* argv[]) {
	//int n1 = 10;
	
	// atoi = converts 'argv[1]' (given with ./a.out) into int
	int n1 = atoi(argv[1]);
	int n2 = 2*n1;

	int fibo1 = fibonnaci_recursive(n1);
	int fibo2 = fibonnaci_recursive(n2);
	int fibo3 = fibonnaci_iterative(n1);

	printf("%d\n",fibo1);
	printf("%d\n",fibo2);
	printf("%d\n",fibo3);
	
	return 0;
}

