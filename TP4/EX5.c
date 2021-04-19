#include <stdio.h>
#include <stdlib.h>

//copies src into dst
void* memcopy(void *dst, const void *src, size_t len) {
	//converts entry pointeurs into char*
	const char* s= src; 
	char* d = dst;

	//loop over 'len' iterations
	while(len--) {
		//copie la source vers la destination
		//en adresse et non en valeur
		*d++ = *s++;
	}
	return d;
}	

//compares src and dst over 'len' caracters
int memcomp(void *src, void *dst, size_t len) {
	char *s = src;
	char *d = dst;

	for (int i =0;i<len;i++) {
		if (*s++ != *d++) {
			return 0;
		}
	}
	
	return 1;
}

//writes 'len' first caracteres of c in src
void* memst(void *src, int c, size_t len) {
	unsigned char *s = src;
	unsigned char c1 = (unsigned char) c; //transforms c in char*

	while(len--) {
		*s++ = c1;
	}
	return src;
}


//------------------------------//
int main(int argc, char* argv[]) {
	char t1[4] = {"abc"};
	char t2[4] = {"def"};
	char t3[4];
	int c = 109271;
	
	int v = memcomp(t1,t2,3);
	memcopy(t1,t2,3);
	int v2 = memcomp(t1,t2,3);
	
	printf("%d\n",v);
	printf("%s\n",t1);
	printf("%d\n",v2);
	printf("%d\n",atoi(memst(t3,c,2)));
	return 0;
}
