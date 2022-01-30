#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

typedef struct {
	int x, y;
} vec2;

DECLARE_VECTOR(vec2)

int main() {
	vec2 v1;

	Vector_vec2 v;
	VectorInit_vec2(&v);
	
	srand(time(0));
	for (uint32_t i = 0; i < 10; i++) {
		v1.x = rand() % 5;
		v1.y = rand() % 5;
		VectorPush_vec2(&v, v1);
	}

	for (uint32_t i = 0; i < v.size; i++) {
		vec2 v2 = VectorGet_vec2(&v, i);
		printf("{%i, %i}\n", v2.x, v2.y);
	}

	VectorFree_vec2(&v);
	return 0;
}