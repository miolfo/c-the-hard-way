#include <stdio.h>

int main(){
	int nmbrs[] = {123,42,3};
	char invalid_name[] = {'H', 'F'};
	char working_name[] = {'H', 'F', '\0'};
	printf("Int size: %ld \n", sizeof(int));
	printf("Char size: %ld \n", sizeof(char));
	printf("Long size: %ld \n", sizeof(long));
	printf("nmbr size: %ld \n", sizeof(nmbrs));
	printf("nmbr array length: %ld \n", sizeof(nmbrs) / sizeof(int));
	printf("invalid_name: %s \n", invalid_name);
	printf("name: %s \n", working_name);
	return 0;
}