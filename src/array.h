#include <stdlib.h>

#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
	size_t length;		// the amount of the array that is in use
	size_t capacity;	// the max size of the array before resizing 
	void *items;
} Array;

void _arr_ensure_size(Array *array, size_t item_size);

#define Array_Init(type, initial_capacity)\
	{\
		.capacity = initial_capacity,\
		.length = 0,\
		.items = (type*) malloc(initial_capacity * sizeof(type))\
	}

/*
Initializes the array using calloc instead of malloc
*/
#define Array_InitC(type, initial_capacity)\
	{\
		.capacity = initial_capacity,\
		.length = 0,\
		.items = (type*) calloc(initial_capacity, sizeof(type))\
	}

#define Array_Append(array, type, value) \
	_arr_ensure_size(&array, sizeof(type));\
	((type*) array.items)[array.length - 1] = (type) value;

#define Array_Get(array, type, index)  (type) ((type *) array.items)[index]

#define Array_SetIndex(array, type, value, index) ( (type *)array.items)[index] = (type) value


#endif