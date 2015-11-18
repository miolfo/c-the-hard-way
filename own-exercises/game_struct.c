#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


struct Game{
	int id;
	char *name;
};

struct Game *Create_game(int id, char*name)
{
	struct Game *game = malloc(sizeof(struct Game));
	game->id = id;
	game->name = name;
	return game;
}

void Delete_game(struct Game *game)
{
	//free(game->name);
	free(game);
}

void Print_game(struct Game *game)
{
	printf("Game %s has id of %d \n", game->name, game->id);
}

int main(int argc, char *argv[]){
	struct Game *game = Create_game(0, "DOTO");
	Print_game(game);
	Delete_game(game);
	
	return 0;
}