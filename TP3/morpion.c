#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//prints the current table
void afficher_ecran(char** table) {
	printf("\n    1   2   3\n");	
	printf("  -------------\n");
	for (int i=0; i<3;i++) {
		printf("%d | %c | %c | %c |\n",i+1,table[i][0],table[i][1],table[i][2]);
		printf("  -------------\n");
	}
	return; 
}


//gets the line where the player wants to play
int choix_ligne() {
	int ligne;
	int valide_ligne = 0;  //will make sure the line is correct
	int position[1]; //stores what player writes
	
	do {
		printf("Entrez un numero de ligne (1; 2 ou 3) : ");
		scanf("%d",position); //asks the player	
		ligne = position[0];

		//tests if the line is correct or not
		if (ligne<=3 && ligne>0) {
			valide_ligne = 1;
		}	
	} while (!valide_ligne);

	return ligne;
}


//gets the column where the player wants to play
int choix_colonne() {
	int colonne;
	int valide_colonne = 0; //will make sure the column is correct
	int position[1]; //stores what player writes
	
	do {
		printf("Entrez un numero de colonne (1; 2 ou 3) : ");
		scanf("%d",position); //asks the player	
		colonne = position[0];
		
		//tests if the colomun is correct or not
		if (colonne<=3 && colonne>0) {
			valide_colonne = 1;
		}
	} while (!valide_colonne);

	return colonne;
}


//checks if there is victory
char verification (char** table) {
	//checks on lines
	for (int i=0;i<3;i++) {
		if (table[i][0] == table[i][1] && table[i][0] == table[i][2] && table[i][0] !='-') {
			return table[i][0];
		}
	}

	//checks on columns
	for (int j=0;j<3;j++) {
		if (table[0][j] == table[1][j] && table[0][j] == table[2][j] && table[0][j] !='-') {
			return table[0][j];
		}
	}

	//checks the diagonal
	if (table[0][0] == table[1][1] && table[0][0] == table[2][2] && table[0][0] !='-') {
		return table[0][0];
	}

	//checks the antidiagonal
	if (table[0][2] == table[1][1] && table[0][2] == table[2][0] && table[2][0] !='-') {
		return table[0][2];
	}

	//by default
	return 0;
}


//modifies the table
void jouer(char **table, char joueur, int compte) {
	int ligne = choix_ligne();		   //gets the line
	int colonne = choix_colonne(); 		   //gets the column
	char position = table[ligne-1][colonne-1]; //looks where the player wants to play

	while (position != '-') { //while the position targeted is not empty
		printf("Case deja prise.\n");
		ligne = choix_ligne();
		colonne = choix_colonne();
		position = table[ligne-1][colonne-1];
	}
	
	table[ligne-1][colonne-1] = joueur;
	
	return;
}


//main function
void jeu() {
	//creates the table :
	// 1) makes each line of the table
	char ligne1[3] = {'-','-','-'};
	char ligne2[3] = {'-','-','-'};
	char ligne3[3] = {'-','-','-'};
	// 2) makes the table (2D)
	char* table[3] = {ligne1,ligne2,ligne3};

	int compteur = 0;	//to switch between 'X' and 'O', counts each turn
	int compte_x = 0;	//stores how many times 'X' has played
	int compte_o = 0;	//stores how many times '0' has played
	int victoire = 0;       //tells if there is victory or not

	afficher_ecran(table);	

	while (!victoire) {
		compteur++;

		if (compteur%2) { //if it's the turn of 'O'
			compte_o++;
			printf("\nJoueur : '0'\n");
			jouer(table,'O',compte_o);
		}
		else {
			compte_x++;			
			printf("\nJoueur : 'X'\n");
			jouer(table,'X',compte_x);
		}
		
		afficher_ecran(table);
		if (compteur == 9) { //if there are 9 turns played and no victory
			victoire = 1;
			printf("Egalite.\n");
			return;
		}
		
		if (compteur>=2 && compteur<9) { //at least 5 turns and less than 9 turns played
			
			victoire = verification(table);
			
			if (victoire == 'X') {
				printf("Victoire des X, bravo !\n");
				return;
			}
			else if (victoire == 'O') {
				printf("Victoire des O, bravo !\n");
				return;
			}
		}
		
	}
	
	return;
}
	
//-------------------------------------------//
int main (int argc, char* argv[]) {
	jeu();
	return 0;
}


