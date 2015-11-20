#ifndef _shape_h
#define _shape_h

typedef struct {
	char *descr;
	int(*init)(void *self, int area);
	void(*describe)(void *self);
	void(*destroy)(void *self);
	int (*area)(void *self);
} Shape;

int Shape_init(void *self, int area);
void Shape_destroy(void *self);
void Shape_describe(void *self);
int Shape_area(void *self);
void *Shape_new(int size, Shape shape, char *descr);
#endif