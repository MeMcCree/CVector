#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

typedef struct {
	int x, y;
} vec2;

DECLARE_VECTOR(vec2)
DECLARE_VECTOR(int)

int main() {
	vec2 v1;

	Vec_vec2 v;
	VecInit_vec2(&v);

	Vec_int vi;
	VecInit_int(&vi);
	
	srand(time(0));
	for (uint32_t i = 0; i < 10; i++) {
		v1.x = rand() % 5;
		v1.y = rand() % 5;
		v.Push(&v, v1);
		vi.Push(&vi, rand() % 99);
	}

	for (uint32_t i = 0; i < v.size; i++) {
		vec2 v2 = v.Get(&v, i);
		printf("{%i, %i} : %i\n", v2.x, v2.y, vi.Get(&vi, i));
	}

	VecFree_vec2(&v);
	VecFree_int(&vi);
	return 0;
}