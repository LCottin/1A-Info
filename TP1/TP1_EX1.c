#include <stdio.h>

//returns the pgcd of a and b 
/*
int pgcd (int a, int b) {
  if (a<=1) {
    return b;
  }
  if (b==1){
    return b;
  }
  else {
    return pgcd(b,a%b);
  }	
}
*/

int pgcd2 (int a, int b) {
  int reste;
  
  while (b>0){
    reste = a%b;
    a = b;
    b = reste;
  }
  return a;
}


int main (int argc, char*argv[]) {
  //int m;
  int l;
  //m = pgcd(14,7);
  l = pgcd2(14,7);
	    
  //printf("%d\n",m);
  printf("%d\n",l);
	    
  return 0;
}
