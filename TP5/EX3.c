#include <stdio.h>
#include <string.h>

#define MAX_STR 64
#define MAX_SONG 100

//defines a song with many arguments
struct song {
	char path[MAX_STR];
	char title[MAX_STR];
	char artist[MAX_STR];
	char album[MAX_STR];
	char kind[MAX_STR];
	int track;
	};

//initialises a song
void initialise(struct song* song1) {
	strcpy(song1->path, "unknown"); //we use -> because it's a pointer
	strcpy(song1->title, "unknown");
	strcpy(song1->artist, "unknown");
	strcpy(song1->album, "unknown");
	strcpy(song1->kind, "unknown");
	song1->track = 0;
	return;
}


//prints every information about a song
void affiche(struct song* song1) {
	if (strcmp(song1->path,"unknown") !=0) {
		printf("\nPath : %s\n",song1->path);
	}
	if (strcmp(song1->title,"unknown") !=0) {
		printf("Titre : %s\n",song1->title);
	}
	if (strcmp(song1->album,"unknown") !=0) {
		printf("Album : %s\n",song1->album);
	}
	if (strcmp(song1->artist,"unknown") !=0) {
		printf("Artiste : %s\n",song1->artist);
	}
	if (strcmp(song1->kind,"unknown") !=0) {
		printf("Genre : %s\n",song1->kind);
	}
	if (song1->track != 0) {
		printf("Numero de piste : %d\n",song1->track);
	}
	return;
}

//counts how many songs there are in the playlist
int nb_chansons(struct song* playlist) {
	int compteur = 0;
	for (int i=0;i<MAX_SONG;i++) {
		if (strcmp(playlist[i].kind,"ROCK")==0) {
			compteur++;
		}
	}
	
	return compteur;
}
	
//adds a song in the playslist
void add_song(struct song* playlist, char* title, char* album, int track, char* kind) {
	int nb = nb_chansons(playlist);
	
	strcpy(playlist[nb].title,title);
	strcpy(playlist[nb].album,album);
	strcpy(playlist[nb].title,title);
	strcpy(playlist[nb].kind,kind);
	playlist[nb].track = track;
	return; 
}

//selects all songs which kind are "rock"
void tri_genre(struct song* genre, struct song* playlist) {
	int numero = 0;
	for (int i=0;i<MAX_SONG;i++) {
		if (strcmp(playlist[i].kind,"ROCK")==0) {
			genre[numero] = playlist[i];
			numero++;
		}
	}
	return;
}

//swap songs in a playlist
void swap(struct song* playlist, int chanson1, int chanson2) {
	struct song song1;
	song1 = playlist[chanson1];
	playlist[chanson1] = playlist[chanson2];
	playlist[chanson2] = song1;
	return;
}


//-----------------------------//
int main(int argc, char* argv[]) {
	
		
	struct song song1;
	enum genre {ROCK, POP, JAZZ, CLASSIQUE};
	//char* liste_genres[4] = {"ROCK", "POP", "JAZZ", "CLASSIQUE"}; 

	//initialise(&song1);
	//affiche(&song1);

	//strcpy(song1.title, "titre");
	//strcpy(song1.album, "langage c");
	//strcpy(song1.artist, "leonard");

	enum genre kind = ROCK; //transforms ROCK into number with enum
	//strcpy(song1.kind,liste_genres[kind]); //gets the kind with the array

	//affiche(&song1);
	
	
	//defines a playlist and initialises it with a loop
	struct song playlist[MAX_SONG];
	for (int i=0;i<MAX_SONG;i++) {
		initialise(&playlist[i]);
	}
	
		
	//int compteur = nb_chansons(playlist);
	//printf("Il y a %d musiques dans la playlist.\n",compteur);
	//add_song(playlist,"titre2","album",3,"rock");
	//affiche(&playlist[1]);

	struct song genre[MAX_SONG];
	strcpy(playlist[0].kind,"ROCK");
	strcpy(playlist[0].title,"titre1");

	strcpy(playlist[1].kind,"JAZZ");
	strcpy(playlist[1].title,"titre2");

	strcpy(playlist[2].kind,"POP");
	strcpy(playlist[3].kind,"JAZZ");
	tri_genre(genre, playlist);

	int cpt = nb_chansons(genre);

	printf("\n");
	affiche(&playlist[0]);
	affiche(&playlist[1]);
	printf("\n");
	swap(playlist,0,1);
	
	affiche(&playlist[0]);
	affiche(&playlist[1]);
	return 0;
}
