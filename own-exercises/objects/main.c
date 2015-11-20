#include "shape.h"
#include <stdio.h>

struct Circle{
	Shape shape;
	int a;
};

typedef struct Circle Circle;

int Circle_init(void *self, int area)
{
	printf("Circle init with area %d\n", area);
	Circle *circle = self;
	circle->a = area;
	return 1;
}

int Circle_area(void *self)
{
	Circle *circle = self;
	printf("Area of circle is %d\n", circle->a);
	return circle->a;
}

void Circle_describe(void *self)
{
	printf("top kek");
}

Shape CircleShape = {
	.init = Circle_init,
	.area = Circle_area
};

int main(int argc, char *argv[])
{
	Circle *circle = Shape_new(sizeof(Circle), CircleShape
	, "Joo ympyrs");
	circle->shape.describe(circle);
	circle->shape.area(circle);
	return 0;
}