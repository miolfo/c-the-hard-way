#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
	Object *obj = self;
	if(obj){
		if(obj->description) free(obj->description);
		free(obj);
	}
}

void Object_describe(void *self)
{
	Object *obj = self;
	printf("%s.\n", obj->description);
}

int Object_init(void *self)
{
	return 1;
}

void *Object_move(void *self, Direction direction)
{
	printf("Can't move there!\n");
	return NULL;
}

int Object_attack(void *self, int damage)
{
	printf("Can't attack that!\n");
	return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
	//Setup the default functions if they already aren't set
	if(!proto.init) proto.init = Object_init;
	if(!proto.describe) proto.describe = Object_describe;
	if(!proto.destroy) proto.destroy = Object_destroy;
	if(!proto.attack) proto.attack = Object_attack;
	if(!proto.move) proto.move = Object_move;
	
	//Make a struct of 1 size, then cast it
	Object *el = calloc(1, size);
	*el = proto;
	
	el->description = strdup(description);
	
	//Init
	if(!el->init(el)){
		printf("Initialization failed!");
		el->destroy(el);
		return NULL;
	} else{
		return el;
	}
}