#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Player{
	char *real_name;
	char *nick_name;
	int mmr;
};

struct Player *Player_create(char *real_name, char *nick_name, int mmr)
{
	struct Player *who = malloc(sizeof(struct Player));
	assert(who != NULL);
	who->real_name = strdup(real_name);
	who->nick_name = strdup(nick_name);
	who->mmr = mmr;
	
	return who;
}

void Player_destroy(struct Player *who)
{
	assert(who != NULL);
	free(who->real_name);
	free(who->nick_name);
	free(who);
}

void Player_print(struct Player *who)
{
	printf("Player %s, nicknamed %s with an mmr of %d\n", who->real_name, who->nick_name, who->mmr);
}

int main(){
	struct Player *rtz = Player_create("Artour Mikälie", "RTZ", 9001);
	printf("Memory location of player is %p \n", rtz);
	Player_print(rtz);
	Player_destroy(rtz);
	return 0;
}
