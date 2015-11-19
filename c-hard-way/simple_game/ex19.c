#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"

int Monster_attack(void *self, int damage)
{
	Monster *monster = self;
	printf("You attack %s!\n", monster->_(description));
	monster->hit_points -= damage;
	
	if(monster->hit_points > 0){
		printf("Still alive...\n");
		return 0;
	} else {
		printf("Ded\n");
		return 1;
	}
}

int Monster_init(void *self)
{
	Monster *monster = self;
	monster->hit_points = 10;
	return 1;
}

Object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack
};

void *Room_move(void *self, Direction direction)
{
	Room *room = self;
	Room *next = NULL;
	
	if(direction == NORTH && Room->north){
		printf("You go north in to \n");
		next = room->north;
	} else if(direction == SOUTH && room->south){
		printf("You go south in to \n");
		next = room->south;
	}else if(direction == EAST && room->east){
		printf("You go east in to \n");
		next = room->east;
	}else if(direction == WEST && room->west){
		printf("You go west in to \n");
		next = room->west;
	}else{
		printf("Can't go there\n");
		next = NULL;
	}
	
	if(next){
		next->_(describe)(next);
	}
	
	return next;
}

int Room_attack(void *self, int damage)
{
	Room *room = self;
	Monster *monster = room->bad_guy;
	
	if(monster) {
		monster->_(attack)(monster, damage);
		return 1;
	} else{
		printf("Nothing there\n");
		return 0;
	}
}

Object RoomProto = {
	.move = Room_move,
	.attack = Room_attack
};

void *Map_move(void *self, Direction direction)
{
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;
	
	next = location->_(move)(location, direction);
	
	if(next) {
		map->location = next;
	}
	return next;
}

int Map_attack(void *self, int damage)
{
	Map *map = self;
	Room *location = map->location;
	
	return location->_(attack)(location, damage);
}

int Map_init(void *self)
{
	Map *map = self;
	
	//Create some rooms
	Room *hall = NEW(Room, "Great hall");
	Room *throne = NEW(Room, "Throne room");
	Room *arena = NEW(Room, "Arena");
	Room *kitchen = NEW(Room, "Kitchen");
	
	arena->bad_guy = NEW(Monster, "Minotaur");
	
	hall->north = throne;
	
	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;
	
	arena->east = throne;
	kitchen->west = throne;
	
	map->start = hall;
	map->location = hall;
	
	return 1;
}

Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

int process_input(Map *game)
{
	printf("\n> ");
	
	char ch = getchar();
	getchar();
	
	int damage = rand() % 4;
	
	switch(ch) {
		case -1:
			printf("Ending\n");
			return 0;
			break;
		case 'n':
			game->_(move)(game, NORTH);
			break;
		case 's':
			game->_(move)(game, SOUTH);
			break;
		case 'e':
			game->_(move)(game, EAST);
			break;
		case 'w':
			game->_(move)(game, WEST);
			break;
		case 'a':
			game->_(attack)(game, damage);
			break;
		case 'l':
			printf("You can go: \n");
			if(game->location->north) printf("North\n");
			if(game->location->south) printf("South\n");
			if(game->location->east) printf("East\n");
			if(game->location->west) printf("West\n");
			break;
		default:
			printf("Invalid command\n");
			break;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	Map *game = NEW(Map, "The hall");
	
	printf("You enter ");
	game->location->_(describe)(game->location);
	
	while(process_input(game)){
		
	}
	return 0;
}