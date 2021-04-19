#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//copies a pointer (DOES NOT WORK)
/*
char* stpcopy (char* dst, const char* src) {
	
	do {
		*dst++ = *src;
	} while(*src++ !=0);
	*dst = '\0';
	
	return dst;	
}
*/

//returns the lengh of the string
int str_len(const char* s) {
	int longueur = 0;
	while(*s++ != 0) {
		longueur++;
	}
	return longueur;
}

//tells if 's1' and 's2' are the same
int str_cmp(const char* s1, const char* s2) {
	if (str_len(s1) > str_len(s2)) {
		return 1;
	}
	else if (str_len(s1) < str_len(s2)) {
		return -1;
	}

	while(*s1++ != 0 ) {
		s2++;
		if (*s1 != *s2) {
			return -10;
		}
	}
	
	return 0; 
}


//concatenate 's1' and 's2'
char* str_cat(char* s1, const char* s2) {
	char* p = s1+str_len(s1);
	strcpy(p,s2);

	return s1;
}


//-----------------------------//
int main (int argc, char* argv[]) {
	char* source = "bonjour";
	char* desti = "bonjours";
	char s1[100] = "bonjour";
	char* s2 = "abc";
	
	//char* x = stpcopy(desti, source);
	//printf("%s\n",source);
	//printf("%s\n",desti);

	printf("%d\n",str_len(s1));
	printf("%d\n", str_cmp(source,desti));
	printf("%s\n",str_cat(s1,s2));
	return 0;
}


