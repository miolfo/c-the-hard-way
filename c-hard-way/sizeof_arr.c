#include <stdio.h>

int main(int argc, char *argv[]){
	int i = 0;
	for(i = 1; i < argc; i++){
		printf("arg %d: %s\n", i, argv[i]);
	}
	
	char *games[] = {
		"dota", "cs", "cscscs"
	};
	
	for(i = 0; i < sizeof(games) / sizeof(*games); i++){
		printf("game %d: %s\n", i, games[i]);
	}
	
	return 0;
}
