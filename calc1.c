#include <stdio.h>

#define INTEGER "INTEGER"
#define PLUS 	"PLUS"
#define EOF 	"EOF"

struct Token{
	char   *type;
	int    value;
};

struct Token* current_token;
char text[100];
int pos=0;

struct Token* get_next_token(){

	char current_char;
	struct Token* temp;
	temp = malloc(sizeof(struct Token));

	if(pos > strlen(text)-1) {
		temp->value = 0;
		temp->type = EOF;
		return temp;
	}

	current_char=text[pos];


	if(isdigit(current_char)) {
		temp->value = current_char-'0';
		temp->type = INTEGER;
		pos++;
		return temp;
	}

	if(current_char == '+') {
		temp->value = (int)current_char;
		temp->type = PLUS;
		pos++;
		return temp;
	}

	return 0;
}

void error()
{
	printf("Error parsing input\n");
	exit(-1);
}

void eat(char *token_type)
{
	if(current_token->type == token_type)
 		current_token = get_next_token();
 	else
 		error();
 }

int expr()
{
	struct Token* left,*op,*right;
	int result;

	left,op,right = malloc(sizeof(struct Token));
	current_token = get_next_token();
	
	left = current_token;
	eat(INTEGER);

	op = current_token;
	eat(PLUS);

	right = current_token;
	eat(INTEGER);

	result = left->value + right->value;

	return result;
}

void main(void)
{

	int result;
	struct Token* current_token;

	current_token = malloc(sizeof(struct Token));

	while(1) {
		printf("calc> ");
		fgets(text,sizeof(text),stdin);
		result = expr();

		printf("%d\n",result);

		current_token = 0;
		pos = 0;

	}

}
