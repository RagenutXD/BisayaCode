#include "hashset.h"

int _hash_alg(char* value, size_t hash_size){
	int index = 0;

	for(int i = 0; i < strlen(value); i++){
		index += (int)value[i];
	}
	index = index % hash_size;
	return index;
}

HashSet HashSet_Init(){
	return (HashSet){
		// i have to manualyy do this because
		// malloc doesnt initialize the indices to NULL
		.set = Array_InitC(char*, 16)
	};
}

void HashSet_Put(HashSet *hashset, char* value){
	int index = _hash_alg(value, hashset->set.capacity);
	char *val = NULL;
	for(int i = 0; i < hashset->set.capacity; i++){
		val = Array_Get(hashset->set, char*, index);
		if(val){
			// strcmp return a 0 if they are equal
			if(strcmp(value, val)){
				printf("%d\n", index);
				index = (index + 1) % hashset->set.capacity;
			}else{
				printf("Value already exists in set\n");
				exit(1);
			}
		}else{
			Array_SetIndex(hashset->set, char*, value, index);
			free(val);
			val = NULL;
			break;
		}
		free(val);
		val = NULL;
	}

}

int HashSet_Contains(HashSet *hashset, char* value) {
	int index = _hash_alg(value, hashset->set.capacity);
	char *val = NULL;
	for(int i = 0; i < hashset->set.capacity; i++){
		val = Array_Get(hashset->set, char*, index);
		if(val){
			if(strcmp(value, val)){
				index = (index + 1) % hashset->set.capacity;
			}else{
				return 1;
			}
		}else{
			free(val);
			val = NULL;
			break;	
		}
		free(val);
		val = NULL;
	}

	return 0;
}