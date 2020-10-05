#include <stdio.h>


void swapStrings(char **destination, char **source);           

int main(){
    // define and initialize str1
    // define and initialize str2

	char *str1 = "Kecel";
	char *str2 = "Hesen";

	printf("str1: %s, str2: %s\n",str1,str2);
	swapStrings(&str1,&str2);
	printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}

void swapStrings(char **destination, char **source){
    // swaps contents of two strings
    // implement this function without using any built in functions
	
	char *temp = *destination;
	*destination = *source;
	*source = temp;
	}

