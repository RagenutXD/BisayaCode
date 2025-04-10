#include <stdio.h>
#include <string.h>
#include "array.h" 

#ifndef HASHSET_H_
#define HASHSET_H_

typedef struct HashSet{
	Array set;
} HashSet;

HashSet HashSet_Init();
void HashSet_Put(HashSet *hashset, char* value);
int _hash_alg(char* value, size_t hash_size);
int HashSet_Contains(HashSet *hashset, char* value);

#endif