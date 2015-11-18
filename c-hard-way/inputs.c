#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("One argument required!\n");
		return 1;
	}
	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++){
		char letter = argv[1][i];
		switch(letter){
			case 'f':
			case 'F':
				printf("F at %d\n", i);
				break;
			case 'm':
			case 'M':
				printf("M at %d\n", i);
				break;
			default:
				printf("Char at %d not mf!\n", i);
				break;
		}
	}
	return 0;
}