#include <ctype.h>
#include <string.h>
#include "array.h"

#ifndef _LEXER_H_
#define _LEXER_H_

typedef enum{
	NUMBER,
	IDENTIFIER,
	EQUALS,
	OPEN_PAREN, CLOSE_PAREN,
	BINARY_OPERATOR,
	LET
} TokenType;


typedef struct{
	char* value;
	TokenType type;
} Token;

Token *tokenize(char* source_code);

#endif