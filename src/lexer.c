#include "lexer.h"

Token _toToken(char* value, TokenType tType){

	return (Token){
		.type = tType,
		.value = value
	};
}

Token *tokenize(char *source_code){
	Array tokens = Array_Init(Token, 16);
	
	int src = 0;
	while(src < strlen(source_code)){
		if(source_code[src] == '('){
			Array_Append(tokens, Token, _toToken(&source_code[src++], OPEN_PAREN));
		} else if(source_code[src] == ')'){
			Array_Append(tokens, Token, _toToken(&source_code[src++], CLOSE_PAREN));
		} else if(source_code[src] == '('){
			Array_Append(tokens, Token, _toToken(&source_code[src++], OPEN_PAREN));
		} else if(source_code[src] == '+' || source_code[src] == '-' || source_code[src] == '/' || source_code[src] == '*'){
			Array_Append(tokens, Token, _toToken(&source_code[src++], BINARY_OPERATOR));
		} else if(source_code[src] == '='){
			Array_Append(tokens, Token, _toToken(&source_code[src++], EQUALS));
		} else {

			// handle multi character tokens
			if(isdigit(source_code[src])){
				char num[strlen(source_code)];
				num[0] = '\0';
				while(src < strlen(source_code) && isdigit(source_code[src])){
					strcat(num, &source_code[src++]);
				}

				Array_Append(tokens, Token, _toToken(num,NUMBER));
			} else if(isalpha(source_code[src])){

				char ident[strlen(source_code)];
				ident[0] = '\0'; // Initialize as an empty string
				while(src < strlen(source_code) && isdigit(source_code[src])){
					strcat(ident, &source_code[src++]);
				}

				Array_Append(tokens, Token, _toToken(ident, IDENTIFIER));

			}

		}

	}

	return tokens.items;
}