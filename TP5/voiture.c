#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NB_CAR 10

//defines a car
struct voiture {
	int puissance;
	int annee;
	int emission;
	int departement;
	char plaque[10];
	char proprietaire[50];
};


//prints information about a car
void affiche(struct voiture v) {
	printf("%s %d %dcv (%dgr/km) : %s (%d)\n",v.plaque,v.annee,v.puissance,v.emission, 							v.proprietaire,v.departement);
	return;
}

//prints car made after 2014
void selection(struct voiture* garage) {
	for (int i=0; i<NB_CAR;i++) {
		if (garage[i].annee >= 2014) {
			affiche(garage[i]);
		}
	}
	return;
}					

//tells if a car has a temporary license plate or not
int immat_temporaire(struct voiture v) {
	if (v.plaque[0]=='W' && v.plaque[1] =='W') {
		return 1;
	}
	return 0;
}

//changes car license plate if they are temporary
void change_mat(struct voiture* v, char* immat){
	if (!immat_temporaire(*v) && immat[0]!='W' && immat[1]!='W') {
		strcpy(v->plaque,immat);
		return;
	}
	printf("Immatriculation incorrecte !\n");
	return;
}

//calculates fiscal power
double puiss_fiscale(struct voiture v) {
	return (v.emission/45)+pow(v.puissance*0.736/40,1.6);
}

//returns the price of the vehicle documentation 
double prix_carte(struct voiture v) {
	double prix_cheval;
	switch (v.departement) {
		case 1:
		case 3:
		case 7:
		case 15:
		case 26:
		case 38:
		case 42:
		case 43:
		case 63:
		case 69:
		case 73:
		case 74:
			prix_cheval = 43.00;
			break;
		case 2:
		case 60:
		case 80:
			prix_cheval = 33.00;
			break;
		case 4:
		case 5:
		case 6:
		case 13:
		case 83:
		case 84: 
			prix_cheval = 51.20;
			break;
		case 8:
		case 10:
		case 51:
		case 52:
			prix_cheval = 37.33;
			break;
		case 9:
		case 11:
		case 12:
		case 30:
		case 31:
		case 32:
		case 34:
		case 46:
		case 48:
		case 54:
		case 55:
		case 57:
		case 65:
		case 66:
		case 81:
		case 82:
		case 88:
			prix_cheval = 44.00;
			break;
		case 14: 
		case 27: 
		case 50: 
		case 61: 
		case 76 :
			prix_cheval = 35.00;
			break;
		case 16: 
		case 17: 
		case 19: 
		case 23: 
		case 24: 
		case 33: 
		case 40: 
		case 47: 
		case 64: 
		case 79: 
		case 86: 
		case 87: 
		case 971 :
			prix_cheval = 41.00;
			break;
		case 972 :
			prix_cheval = 30.00;
			break;
		case 973 : 
			prix_cheval = 42.50;
			break;
		case 21: 
		case 22: 
		case 25: 
		case 29: 
		case 35: 
		case 39: 
		case 56: 
		case 58: 
		case 70: 
		case 71: 
		case 89: 
		case 90: 
		case 974 :
			prix_cheval = 51.00;
			break;
		case 976 :
			prix_cheval = 20.00;
			break;
		case 44: 
		case 49: 
		case 53: 
		case 72: 
		case 85 :
			prix_cheval = 48.00;
			break;
		case 75: 
		case 77: 
		case 78: 
		case 91 ... 95 :
			prix_cheval = 46.15;
			break;
		case 59: 
		case 62 :
			prix_cheval = 42.60;
			break;
		case 18: 
		case 28: 
		case 36: 
		case 37: 
		case 41: 
		case 45 :
			prix_cheval = 49.80;
			break;
		case 20 : //both North and South Corsica are the same
			prix_cheval = 27.00;
			break;
	}
	return prix_cheval*puiss_fiscale(v);
}

//tells which license plate comes after
void prochaine_immat(char* immat, char* suivante) {
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	enum alpha {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
	int chiffre = immat[3]*100+immat[4]*10+immat[5];

	suivante[2]='-';
	suivante[6]='-';

	chiffre++;	
	if (chiffre==1000) {
		chiffre = 0;
		suivante[3]='0';
		suivante[4]='0';
		suivante[5]='0';
		if (immat[1]=='Z'){ //like (*Z-***-**)
			enum alpha c = immat[0];
			suivante[0] = alphabet[c+1];
			suivante[1]='A';
		}
		else {
			enum alpha c = immat[1];
			suivante[1] = alphabet[c+1];
		}

		if (immat[0]=='Z') { //like (Z*-***-**)
			enum alpha c = immat[8];
			suivante[8] = alphabet[c+1];
			suivante[0] = 'A';
		}
		else {
			enum alpha c = immat[8];
			suivante[8] = alphabet[c=1];
		}
	
		if (immat[8]=='Z') { //like (**-***-*Z)
			enum alpha c = immat[7];
			suivante[7] = alphabet[c+1];
			suivante[8] = 'A';
		}
		else {
			enum alpha c = immat[7];
			suivante[7] = alphabet[c+1];
		}
	}
	
	//deals with special cases
	for (int i=0;i<9;i++){
		switch (immat[i]) {
			case 'I' : 
				suivante[i]='J';
				break;
			case 'O' :
				suivante[i]='P';
				break;
			case 'V' :
				suivante[i]='W';
				break;
		}
	}

	//makes sure it's not a temporary license plate
	if (suivante[0]=='W' && suivante[1]=='W') {
		enum alpha c = suivante[1];
		suivante[1] = alphabet[c+1];
	}
	
	return;
}


//-------------------------//
int main(int arvc, char*argv[]) {
	struct voiture garage[NB_CAR]; 
	char suivante[10] = "**-***-**";
	
	strcpy(garage[0].plaque,"AN-427-MZ");
	strcpy(garage[0].proprietaire,"COTTIN");
	garage[0].annee = 1991;
	garage[0].puissance = 96;
	garage[0].emission = 168;
	garage[0].departement = 33;
	
	/*
	affiche(garage[0]);
	printf("La voiture a une immatriculation temporaire : %d.\n",immat_temporaire(garage[0]));
	selection(garage);

	change_mat(&garage[0],"WW-123-AZ");
	change_mat(&garage[0],"AB-328-MA");

	double puissance_fiscale = puiss_fiscale(garage[0]);
	printf("Puissance fiscale de la voiture : %lf\n",puissance_fiscale);

	double prix = prix_carte(garage[0]);
	printf("Prix de la carte grise : %lf€\n",prix);
	*/

	prochaine_immat(garage[0].plaque,suivante);
	printf("plaque actuelle : %s\nPlaque suivante : %s\n",garage[0].plaque, suivante);
	return 0;
}
