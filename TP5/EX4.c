#include <stdio.h>
#include <math.h>
#include <string.h>

#define EPSILON 0.00000000001

//returns a point
void saisir_point(double* coordonnees) {
	printf("\nEntre l'abscisse : ");
	scanf("%lf",&coordonnees[0]);
	printf("Entre l'ordonnee : ");
	scanf("%lf",&coordonnees[1]);
	return;
}

//returns distance between two points
double distance(double* co1, double* co2) {
	return sqrt((co1[0]-co2[0])*(co1[0]-co2[0]) + (co1[1]-co2[1])*(co1[1]-co2[1]));
}

int compare(double A, double B) {
	if (fabs(A-B) <= EPSILON) {
		return 1;
	}
	return 0;
}
//tells how the triangle ABC is
void nature_tri(double* A, double* B, double* C, char* nature) {
	double ab = distance(A,B);
	double bc = distance(B,C);
	double ac = distance(A,C);

	if (ab==bc || ab==ac || bc==ac)	{ //checks if it's isosceles triangle
		//cheks if it's square triangle
		if (compare(pow(ab,2),pow(ac,2)+pow(bc,2)) || 
		    	compare(pow(ac,2),pow(ab,2)+pow(bc,2)) || 
		   		 compare(pow(bc,2),pow(ab,2)+pow(ac,2))) {
				 
			strcpy(nature,"isocele rectangle");
			return;
		}
		strcpy(nature,"isocele");		
		return;
	}
	
	else if (ab==bc && ab==ac) { //checks if it's equilateral trianle  
		strcpy(nature,"equilatéral");
		return;
	}
	
	//default
	nature = "scalene";
	return;
}



//-----------------------//
int main(int argc, char*argv[]) {
	double coordonnees1[2];
	double coordonnees2[2];
	double coordonnees3[2];
	char nature[50];

	saisir_point(coordonnees1);
	saisir_point(coordonnees2);
	saisir_point(coordonnees3);

	nature_tri(coordonnees1,coordonnees2,coordonnees3,nature);
	printf("%s\n",nature);

	//printf("abscisse : %lf, ordonnee : %lf\n",coordonnees1[0],coordonnees1[1]);
	//printf("la distance entre ces points est : %lf\n\n",distance(coordonnees1,coordonnees2));
	return 0;
}

