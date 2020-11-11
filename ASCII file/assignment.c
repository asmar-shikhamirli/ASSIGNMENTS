#include <stdio.h>


void sortfunc(char *source, char *integer, char *nonInteger);

void sortfunc(char *source, char *integer, char *nonInteger){
	int i = 0, index1 = 0, index2 = 0;

	for ( ; source[i]!='\0'; i++){
		if(source[i]>48 && source[i]<= 57){
			integer[index1]=source[i];
			index1++;
		}
		else{
			nonInteger[index2]= source[i];
			index2++;
		}
	}
	integer[index1] = '\0';
	nonInteger[index2] = '\0';
}

int main(){

	char source[] = "asdkh!#$%^s651sd1s5";
	char integer[256];
	char nonInteger[256];

	printf("source: %s\n", source);
	sortfunc(source, integer, nonInteger);
	
	printf("non integer: %s\n", nonInteger);
	printf("integer: %s\n", integer);
}




