#include <stdio.h>
#include <stdlib.h>

//says if 'annee' is a leap year 
int est_bissextile(int annee) {
	return (annee%4==0 && annee%100) || (annee%400==0);
}


//gives how many days there are in the months 
int nombre_jours(int mois, int annee) {
	switch (mois) {
		case 1 : return 31;
		case 3 : return 31;
		case 5 : return 31;
		case 7 : return 31;
		case 8 : return 31;
		case 10 : return 31;
		case 12 : return 31;
		case 4 : return 30;
		case 6 : return 30;
		case 9 : return 30;
		case 11 : return 30;
		case 2 : return (28+est_bissextile(annee));
		default : return 0;
	}
}	


//tells which day is the date
int jour_semaine(int jour, int mois, int annee) {
	if (mois <3) {
		int z = annee - 1;
		return ((23*mois/9 + jour + 4 + annee + z/4 - z/100 + z/400)%7);
	}
	return ((23*mois/9 + jour+4+annee + annee/4 - annee/100 + annee/400 - 2)%7);

}	

//-----------------------------------//
int main(int argc, char* argv[]) {
	int annee = atoi(argv[3]);
	int mois = atoi(argv[2]);
	int jour = atoi(argv[1]);
	
	printf("%d\n",est_bissextile(annee));
	printf("Le mois n°%d comptient %d jours.\n",mois,nombre_jours(mois,annee));
	printf("Cette date est le %deme jour de la semaine.\n",jour_semaine(jour,mois,annee));
	
	return 0;
}
