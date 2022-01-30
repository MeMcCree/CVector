#ifndef VECTOR_H
#define VECTOR_H

#include <inttypes.h>
#include <stdlib.h>

#define INIT_CAPACITY 8
#define CAPACITY_MUL 2

#define DECLARE_VECTOR(T)																															\
	typedef struct Vec_##T Vec_##T; 																										\
	struct Vec_##T {       																															\
		T* data;					 																																\
		uint32_t size;			 																															\
		uint32_t capacity;	 																															\
		T (*Get)(Vec_##T*, uint32_t);																											\
		void (*Set)(Vec_##T*, uint32_t, T);																								\
		void (*Push)(Vec_##T*, T);																												\
	};				 																																					\
\
	void VecFree_##T(Vec_##T* v) {																											\
		free(v->data);																																		\
	}																																										\
\
	T VecGet_##T(Vec_##T* v, uint32_t idx) {																						\
		return v->data[idx];																															\
	}																																										\
\
	void VecSet_##T(Vec_##T* v, uint32_t idx, T val) {																	\
		v->data[idx] = val;																																\
	}																																										\
\
	void VecExpand_##T(Vec_##T* v) {																										\
		v->capacity *= CAPACITY_MUL;																											\
		T* tmp = v->data;																																	\
		v->data = malloc(sizeof(T) * v->capacity);																				\
		for (uint32_t _idx = 0; _idx < v->size; _idx++) VecSet_##T(v, _idx, tmp[_idx]);		\
		free(tmp);																																				\
	}																																										\
\
	void VecPush_##T(Vec_##T* v, T val) {																								\
		if (v->size == v->capacity - 1) VecExpand_##T(v);																	\
		VecSet_##T(v, v->size++, val);																										\
	} 																																									\
\
	void VecInit_##T(Vec_##T* v) {																											\
		v->data = malloc(sizeof(T) * INIT_CAPACITY);																			\
		v->size = 0;																																			\
		v->capacity = INIT_CAPACITY;																											\
		v->Get = VecGet_##T;																															\
		v->Set = VecSet_##T;																															\
		v->Push = VecPush_##T;																														\
	}
#endif