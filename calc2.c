#include <stdio.h>
#include <ctype.h>

#define INTEGER "INTEGER"
#define PLUS 	"PLUS"
#define MINUS 	"MINUS"
#define EOF		"EOF"

struct Token{
	char   *type;
	int    value;
};

struct Token* current_token;
char current_char;
char text[100];
int pos=0;


void str_cat(char *dest, char source ) 
{
   *(dest) = source;
   *(dest+1) = '\0';
}

void error()
{
	printf("Error Parsing Input\n");
	exit(-1);
}

void advance()
{
	pos++;
	if(pos > strlen(text)-1) {
		current_char = 0;
	}
	else {
		current_char = text[pos];	
	}

}

void skip_whitespace()
{
	while (current_char != NULL && isspace(current_char)) {
		advance();	
	}
}

int integer()
{
	char  *result=malloc(0x100);
	int k = 0;
	while (current_char != NULL && isdigit(current_char)) {
		str_cat(result + k,current_char);
		advance();
		k++;
	}
    
    int retInt = atoi(result);
	free(result);  
    return retInt;
}		

struct Token* get_next_token()
{
	struct Token *temp;

	temp = malloc(sizeof(struct Token));
	current_char = text[pos];
	
	
	while (current_char != NULL) {
		if (isspace(current_char)) {
			skip_whitespace();
			continue;	
		}

		if (isdigit(current_char)) {
			temp->type = INTEGER;
			temp->value = integer();
			return temp;
		}

		if (current_char == '+') {
			advance();
			temp->type = PLUS;
			temp->value = '+' + '0';	
			return temp;
		}

		if (current_char == '-') {
			advance();
			temp->type = MINUS;
			temp->value = '-' + '0';	
			return temp;
		}

		temp->type = EOF;
		temp->value = NULL;
		return temp;
	}
}

void eat(char *token_type)
{
	if (current_token->type == token_type) {
		current_token = get_next_token();
	}
	else {
		error();
	}
}

int expr()
{
	struct Token* left,*op,*right;
	int result;

	left, op, right = malloc(sizeof(struct Token));
	current_token = get_next_token();

	left = current_token;
	eat(INTEGER);

	op = current_token;

	if (op->type == PLUS ) {
		eat(PLUS);
	}
	else {
		eat(MINUS);	
	}

	right = current_token;
	eat(INTEGER);
	
	if (op->type == PLUS) {
		result = left->value + right->value;	
	}
	else {
		result = left->value - right->value;
	}	

	return result;
}

void main(void)
{
	int result;

	current_token=malloc(sizeof(struct Token));
	
	while(1) {
		printf("calc> ");
		fgets(text,sizeof(text),stdin);
		result=expr();

		printf("%d\n",result);

		pos=0;	

	}
}
