#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//return f(x)
double f_x(double x) {
	double a,b,c;

	printf("Entre a : ");
	scanf("%lf",&a);
	printf("Entre b : ");
	scanf("%lf",&b);
	printf("Entre c : ");
	scanf("%lf",&c);

	return (a*x*x+b*x+c);
}

//returns the 0 of the function
void racine() {
	double a,b,c;

	printf("Entre a : ");
	scanf("%lf",&a);
	printf("Entre b : ");
	scanf("%lf",&b);
	printf("Entre c : ");
	scanf("%lf",&c);
	
	double delta = b*b-4*a*c;
	if (delta<0) {
		printf("Pas de racines reelles.\n");
	}
	else if (delta ==0) {
		printf("Une racine double : %lf.\n",-b/(2*a));
	}
	else {
		double x1 =(-b-sqrt(delta))/(2*a);
		double x2 =(-b+sqrt(delta))/(2*a);
		printf("2 racines réelles distinctes : x1 = %lf et x2 = %lf.\n",x1,x2);
	}
	return;
}


//-------------------------//
int main(int argc, char* argv[]) {
	double x = atoi(argv[1]);

	printf("f(%lf) = %lf\n",x,f_x(x));
	racine();
	return 0;
}	
