#ifndef VECTOR_H
#define VECTOR_H

#include <inttypes.h>
#include <stdlib.h>

#define INIT_CAPACITY 8
#define CAPACITY_MUL 2

#define DECLARE_VECTOR(T)																															\
	typedef struct {       																															\
		T* data;					 																																\
		uint32_t size;			 																															\
		uint32_t capacity;	 																															\
	} Vector_##T;					 																															\
\
	void VectorInit_##T(Vector_##T* v) {																								\
		v->data = malloc(sizeof(T) * INIT_CAPACITY);																			\
		v->size = 0;																																			\
		v->capacity = INIT_CAPACITY;																											\
	}																																										\
\
	void VectorFree_##T(Vector_##T* v) {																								\
		free(v->data);																																		\
	}																																										\
\
	T VectorGet_##T(Vector_##T* v, uint32_t idx) {																			\
		return v->data[idx];																															\
	}																																										\
\
	void VectorSet_##T(Vector_##T* v, uint32_t idx, T val) {														\
		v->data[idx] = val;																																\
	}																																										\
\
	void VectorExpand_##T(Vector_##T* v) {																							\
		v->capacity *= CAPACITY_MUL;																											\
		T* tmp = v->data;																																	\
		v->data = malloc(sizeof(T) * v->capacity);																				\
		for (uint32_t _idx = 0; _idx < v->size; _idx++) VectorSet_##T(v, _idx, tmp[_idx]);\
		free(tmp);																																				\
	}																																										\
\
	void VectorPush_##T(Vector_##T* v, T val) {																					\
		if (v->size == v->capacity - 1) VectorExpand_##T(v);															\
		VectorSet_##T(v, v->size++, val);																									\
	}
#endif