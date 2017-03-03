
#include"stack.h"

void init(stack *s) {
	s->ct = 0;
}
	
void push(stack *s, direct t) {
	
	if(s->ct == 0) {
		s->a = malloc(sizeof(direct));
		s->a[s->ct].a = t.a ;
		s->a[s->ct].i = t.i;
		s->ct++;
	}
	else {
		s->a = realloc(s->a, sizeof(int) * (s->ct+1));
		s->a[s->ct].a = t.a ;
		s->a[s->ct].i = t.i;
		s->ct++;
	}
}			

direct pop(stack *s) {
	s->ct--;
	return s->a[s->ct];
}
	
int full(stack *s) {
	return;
}	 
	
int empty(stack *s) {
	if(!s->ct)
		return 1;
	return 0;	
}		
