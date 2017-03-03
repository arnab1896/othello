
#include"basic.h"

void creatmb() {
	
	int i, j;
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			a[i][j] = 0;
		}
	}
		a[3][3] = a[4][4] = 1;
		a[3][4] = a[4][3] = 2;
}

// We supply the coordinates to the func to see if the move is valid

int valid(int x, int y, int turn, int st) {
	
	stack *s;
	direct z;
	int cnt = 0;
	s = malloc(sizeof(stack));
	init(s);
	int i, j = 0, t;
	
	if(turn == P1)
		t = 2;
	else
		t = 1;
							 
	// First we go left.. note that y is constant
		for(i = x; i > 0; i--) {
			if(a[i-1][y] == t)
				continue;
			else {
				i--;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((x - i) == 1) && !(a[i][y] == 0) && !(a[i][y] == t)  && !(x == i)) {
			if(st == VMOV)
				return 1; 
			z.a = LEFT; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}
			if(st == COMP2) {
				b[x][y] = b[x][y] + (x-i);
			}
			if(st == COMP3) {
				cnt = cnt + (x - i);
			}			 
			push(s, z);
		}	
			
	// Second we go right.. note that y is constant
		for(i = x; i < 7; i++) {
			if(a[i+1][y] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((i - x) == 1) && !(a[i][y] == 0) && !(a[i][y] == t) && !(x == i)) { 
			if(st == VMOV)
				return 1; 
			z.a = RIGHT; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + (i - x);
			}	
			if(st == COMP3) {
				cnt = cnt + (i - x);
			}	
			push(s, z);
		}	
					
	// Third we go up.. note that x is constant
		for(i = y; i > 0; i--) {
			if(a[x][i-1] == t)
				continue;
			else {
				i--;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((y - i) == 1) && !(a[x][i] ==0) && !(a[x][i] == t) && !(y == i)) { 
			if(st == VMOV)
				return 1; 
			z.a = UP; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + (y-i);
			}	
			if(st == COMP3) {
				cnt = cnt + (y - i);
			}	
			push(s, z);
		}	
	// Fourth we go down.. note that x is constant
		for(i = y; i < 7; i++) {
			if(a[x][i+1] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((i - y) == 1) && !(a[x][i] == 0) && !(a[x][i] == t) && !(y == i)) {
			if(st == VMOV)
				return 1; 
			z.a = DOWN; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + (i - y);
			}	
			if(st == COMP3) {
				cnt = cnt + (i-y);
			}	
			push(s, z);	
		}		
	
	// Fifth we go DIAGONALLY RIGHT DOWN.. 
		for(i = 1; ((x+i) <= 8 && (y+i) <= 8); i++) {
			if(a[x+i][y+i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x+i-1][y+i-1] == 0) && !(a[x+i-1][y+i-1] == t)) {
			if(st == VMOV)
				return 1; 
			z.a = DDOWNR; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	
			if(st == COMP3) {
				cnt = cnt + i;
			}	
			push(s, z);		
		}
			
	// Sixth we go DIAGONALLY LEFT UP.. 
		for(i = 1; ((x-i) >= 0 && (y-i) >= 0); i++) {
			if(a[x-i][y-i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		if(i == 1)
			i++;
		
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x-i+1][y-i+1] == 0) && !(a[x-i+1][y-i+1] == t)) { 
			if(st == VMOV)
				return 1; 
			z.a = DUPL; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	 
			if(st == COMP3) {
				cnt = cnt + i;
			}	
			push(s, z);		
		}			
	
	// Seventh we go DIAGONALLY RIGHT UP.. 
		for(i = 1; ((x+i) <= 8 && (y-i) >= 0 ); i++) {
			if(a[x+i][y-i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		if(i == 1)
			i++;
		
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x+i-1][y-i+1] == 0) && !(a[x+i-1][y-i+1] == t)) { 
			if(st == VMOV)
				return 1; 
			z.a = DUPR; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	 
			if(st == COMP3) {
				cnt = cnt + i;
			}	
			push(s, z);		
		}			
	
	// Eighth we go DIAGONALLY LEFT DOWN.. 
		for(i = 1; ((x-i) >= 0 && (y+i) <= 8 ); i++) {
			if(a[x-i][y+i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		if(i == 1)
			i++;
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x-i+1][y+i-1] == 0) && !(a[x-i+1][y+i-1] == t)) { 
			if(st == VMOV)
				return 1; 
			z.a = DDOWNL;
			z.i = i; //VALID
			if(st == COMP1) {
				return 1;
			}	
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	 
			if(st == COMP3) {
				cnt = cnt + i;
			}	
			push(s, z);		
		}
		if(st == VMOV) 
			return -1;
		if(st == COMP1)
			return -1;
		if(st == COMP2)
			return -1;		
		if(st == COMP3) {
			if(cnt != 0) {
				if(b[x][y] > g->p) {
					g->p = b[x][y];
					g->x = x;
					g->y = y;
					g->i = cnt;
				}
				else if(b[x][y] == g->p) {
					if(g->i < cnt) {
						g->x = x;
						g->y = y;
						g->i = cnt;		
					}
				}
			}
			return 1;
		}				
			
		if(empty(s)) {	
			return 0;
		}
		else {		
			while(!empty(s)) {
				z = pop(s);
				change(z.a, z.i, x, y, turn);
			}	 	
		}
	return -50;										
}

void change(short int c, short int b, int x, int y, int t) {
	
	int i;
	
	switch(c) {
		case(LEFT): {
				for(i = x; i > b; i--) 
					a[i][y] = t;
		}
		break;
		
		case(RIGHT): {
				for(i = x; i < b; i++)
					a[i][y] = t;
		}
		break;			
		
		case(UP): { 
			for(i = y; i > b; i--) 
				a[x][i] = t;
		}
		break;
		
		case(DOWN): {
			for(i = y; i < b; i++)
				a[x][i] = t;
		}
		break;	
		
		case(DUPR): {
			for(i = 0; i < b; i++) 
				a[x+i][y-i] = t;
		}
		break;	
		
		case(DUPL): {
			for(i = 0; i < b; i++) 
				a[x-i][y-i] = t;
		}
		break;		
			
		case(DDOWNR): {
			for(i = 0; i < b; i++) 
				a[x+i][y+i] = t;
		}
		break;
		
		case(DDOWNL): {
			for(i = 0; i < b; i++) 
				a[x-i][y+i] = t;
		}
		break;													
	}	
}	
  										
							
								
			
