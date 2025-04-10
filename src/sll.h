
#ifndef SLL_H_
#define SLL_H_

typedef struct SLLNode{
	void *value;
	SLLNode* next;
} SLLNode;

#define SLL_Init(type,val,nxt)\
	{\
		.value = (type *) val,\
		.next = nxt\
	}


#endif