#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_CHARS 64
#define MAX_PLAYERS 100

struct Player{
	char name[MAX_CHARS];
	int mmr;
};

struct Player_list{
	struct Player players[MAX_PLAYERS];
	int player_count;
};

struct Player *Create_player(char* name, int mmr);
void Print_player(struct Player *player);

void Add_player(char* name, int mmr, struct Player_list *list){
	struct Player *p = Create_player(name, mmr);
	list->players[list->player_count+1] = *p;
	list->player_count = list->player_count + 1;
	free(p);
}

struct Player_list *Create_list(){
	struct Player_list *pl = malloc(sizeof(struct Player_list));
	pl->player_count = 0;
	return pl;
}

void Print_list(struct Player_list *list)
{
	printf("%d players in list \n", list->player_count);
	int count = list->player_count;
	int i = 0;
	for(i = 0; i < count; i++){
		Print_player(&list->players[i]);
	}
}

struct Player *Create_player(char* name, int mmr)
{
	struct Player *p = malloc(sizeof(struct Player));
	strcpy(p->name, name);
	p->mmr = mmr;
	return p;
}

void Print_player(struct Player *player)
{
	printf("Player named %s has an mmr of %d\n", player->name, player->mmr);
}

int main(int argc, char* argv[])
{
	//struct Player *player = Create_player("Hessu Hopo", 609);
	//Print_player(player);
	//free(player);
	struct Player_list *list = Create_list();
	Add_player("Hessu Hopo", 609, list);
	Add_player("Hessu 23", 333, list);
	Print_list(list);
	free(list);
	return 0;	
}