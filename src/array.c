#include "array.h"

void _arr_ensure_size(Array *array, size_t item_size){
	if(array->length == array->capacity){
		array->capacity *= 2;
		array->items = realloc(array->items, array->capacity * item_size);
	}
	array->length++;
}
