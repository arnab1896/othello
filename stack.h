// Reason I'm using a stack is to enhance the reusability of the valid function
#include"impdef.h"
typedef struct stack {
	direct *a;
	int ct;
}stack;

void init(stack *s);
void push(stack *s, direct t);
direct pop(stack *s);
int full(stack *s);
int empty(stack *s);	
