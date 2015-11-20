#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "shape.h"

void Shape_destroy(void *self)
{
	Shape *shape = self;
	if(shape){
		if(shape->descr) free(shape->descr);
		free(shape);
	}
}

void Shape_describe(void *self)
{
	Shape *shape = self;
	printf("%s\n", shape->descr);
}

int Shape_init(void *self, int area)
{
	printf("Def shape init");
	return 1;
}

int Shape_area(void *self)
{
	printf("Def shape area");
	return -1;	
}

void *Shape_new(int size, Shape shape, char *descr)
{
	if(!shape.describe) shape.describe = Shape_describe;
	if(!shape.area) shape.area = Shape_area;
	
	Shape *s = calloc(1, size);
	*s = shape;
	s->descr = strdup(descr);
	int initialized = s->init(s, 3);
	if(!initialized){
		printf("Init fail\n");
		s->destroy(s);
		return NULL;
	}

	return s;
}