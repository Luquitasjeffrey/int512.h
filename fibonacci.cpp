/*
here is a code that generates the fibonacci seqence and print it in decimal.
*/
#include "int512.h"
int main(void){
	int512 f1=r0(),f2=r0(),f3=r0();
	f1.x[0]=1;
	for(int i=0; i<=736; i++){
	f3=f2;	
	f2=f1;
	f1=sumar(f2,f3);
	printf("\nfibonacci(%d)=",i);
	printd(f3);
	}
}
