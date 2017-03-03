#include"start.h"
#include<ncurses.h>

int t = 2;
int r3;
	
void call() {
	
	initscr();

	rec();
	fetch("Letters/o.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/t.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/h.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/e.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/l.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/l.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/o.txt");
	napms(1000);
	clear();
	
	napms(2000);
	clear();
}	


void fetch(char *s) {
	
	int i = 0, j = 0;
	FILE *f;
	f = fopen(s, "r");
	while(1) {
		fscanf(f, "%d", &b[j++][i]);
		if (j == 8) {
			j = 0;
			i++;
		}
		if(i == 8) 
			break;	 
	}
	print();
	fclose(f);
}				

void print() {
	int i = 0, j = 0;
	refresh();
	
	for(i = 0; i < 8; i++) {
		move(15+i, 60);
		for(j = 0; j < 8; j++) {
			if(b[j][i] == 0) {
				attrset(COLOR_PAIR(5)); 
				printw(" ");
			}	
			else {
				attrset(COLOR_PAIR(2));
				printw(" ");		
			}	
		}
		printw("\n");
	}
	refresh();
}			

void rec () {
	
	fetch("Letters/o.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/t.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/h.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/e.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/l.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/l.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/o.txt");
	napms(LAG_1);
	clear();
}	

void lag() {
	int i;
	for(i = 0; i < 3; i++) {
		printw(" ");
		refresh();
		napms(LAG_2);
	}	
}	
	
void menu() {
	
	int i, j;
	int cnt = 1;
	
	clear();
	
	move((LINES/2) - 3, (COLS/2) -20);
	attrset(COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
	
	printw(" O");
	refresh();
	lag();
	printw("T");
	refresh();
	lag();
	printw("H");
	refresh();
	lag();
	printw("E");
	refresh();
	lag();
	printw("L");
	refresh();
	lag();
	printw("L");
	refresh();
	lag();
	printw("O");
	refresh();
	lag();	
	napms(1000);
	attroff(COLOR_PAIR(5));
	attroff(A_UNDERLINE);
	move((LINES/2) - 2, (COLS/2) -8);
	printw("1 -> START\n");
	move((LINES/2) - 1, (COLS/2) -8);
	printw("2 -> LOAD\n");
	move((LINES/2) , (COLS/2) -8);
	printw("3 -> HELP\n");
	move((LINES/2) + 1, (COLS/2) -8);
	printw("4 -> EXIT\n");
	move((LINES/2) + 3, (COLS/2) -8);
				
	printw("\n\n-> Select your choice.......");
	scanw("%d", &i);
	
	switch(i) {
		case 1: {
			clear();
			move((LINES/2) - 3, (COLS/2) -9);
			printw("&&&& &&& && & 1. Vs Human & && &&& &&&&\n");
			move((LINES/2) - 2, (COLS/2) -9);
			printw("&&&& &&& && & 2. Vs Computer & && &&& &&&&\n");
			move((LINES/2), (COLS/2) -9);
			printw("3 -> Back\n");
			scanw("%d", &j);
			switch(j) {
				case 1:
					clear();
					r3 = 1;
					printw("VS HUMAN [");
					init_pair(1, COLOR_YELLOW, COLOR_BLUE);
					attrset(COLOR_PAIR(1));
					creatmb();
					printb();
					vs_human();
				break;
				case 2: {
					int k;
					clear();
					move((LINES/2) - 3, (COLS/2) -9);
					printw("1. Easy\n");
					move((LINES/2) - 2, (COLS/2) -9);
					printw("2. Medium\n");
					move((LINES/2) - 1, (COLS/2) -9);
					printw("3. Hard\n");
					move((LINES/2) + 1, (COLS/2) -9);
					printw("4. Back\n");
					printw("Enter your choice\n");
					scanw("%d", &k);
					switch(k) {
						case 1: {
							r3 = COMP1;
							clear();
							printw("VS COMP [");
							init_pair(1, COLOR_YELLOW, COLOR_BLUE);
							attrset(COLOR_PAIR(1));
							creatmb();
							printb();
							vs_comp1();
						}	
						break;
						case 2: {
							r3 = COMP2;
							clear();
							printw("VS COMP [");
							init_pair(1, COLOR_YELLOW, COLOR_BLUE);
							attrset(COLOR_PAIR(1));
							creatmb();
							printb();
							vs_comp2();
						}
						break;
						case 3: {	
							r3 = COMP3;
							clear();
							printw("VS COMP [");
							init_pair(1, COLOR_YELLOW, COLOR_BLUE);
							attrset(COLOR_PAIR(1));
							creatmb();
							printb();
							vs_comp3();
						}
						break;
						case 4: {
							menu();
						}
						break;		
					}
				}				
				break;
				
				case 3: {
					menu();
				}
				break;	
			}			
		}		
		break;
		
		case 2: {
			load();
		}	
		break;
		
		case 3: {
			clear();
			refresh();
			char a;
			FILE *f;
			f = fopen("Help/Guide.txt", "r");
			while((fscanf(f, "%c", &a)) != EOF) {
				printw("%c", a);
				refresh();
			}
			fclose(f);
			getch();
			menu();
		}		  		
		break;
		
		case 4: {
			endwin();
			exit(1);
		}	
		break;
	}
}								

void printb() {
	
	int i, j, k = 5, l;
	int b, w;
	
	b = 0;
	w = 0;
	
	printw("Type -1 to Save]\n");
	printw("Type -2 to quit");
	
	for(i = 0; i < 8; i++) {
		for(j = 0 ; j < 8; j++) {
			if(a[i][j] == 2)
				b++;
			else if(a[i][j] == 1)
				w++;	
		}
	}
	
	attrset(COLOR_PAIR(3));
	move(1, 70);
	printw(" %d ", w);
	
	attrset(COLOR_PAIR(4));
	move(1, 75);
	printw(" %d ", b);
		
	attrset(COLOR_PAIR(5) | A_BOLD);
	
	move(k,53);
	printw(" ");
	for(i = 0; i < 8; i++)  
		printw("  %d  ", i);
	k++;
	printw("\n");
	
	move(k,52);
	for(i = 0; i < 7; i++) 
		printw("  --  ");
	k++;
	printw(" \n");
		
	for(i = 0; i < 8; i++) {
		for(l = 0; l < 2; l++) {
			move(k, 50);
			printw("   ");
			attrset(COLOR_PAIR(7));
			for(j = 0; j < 8; j++)
				printw("     ");
			printw(" ");	
			attrset(COLOR_PAIR(5));	
			printw("   ");	
			k++;
		}	
		move(k, 50);
		attrset(COLOR_PAIR(5) | A_BOLD);	
		printw("%d |", i);
		attrset(COLOR_PAIR(7));
		printw(" ");
		for(j = 0; j < 8; j++) {
			if(a[j][i] == 0) {
				attrset(COLOR_PAIR(7)); 
				printw("  _  ");
			}	
			else if(a[j][i] == 1) {
				attron(COLOR_PAIR(3) | A_BOLD);
				printw("  O  ");
				attroff(COLOR_PAIR(3) | A_BOLD);
			}	
			else {
				attron(COLOR_PAIR(4) | A_BOLD);
				printw("  O  ");
				attroff(COLOR_PAIR(4) | A_BOLD);				
			}
			attrset(COLOR_PAIR(2));		
		}
		k++;
		attrset(COLOR_PAIR(5) | A_BOLD);
		printw("| %d", i);
	}
	
	for(l = 0; l < 2; l++) {
			move(k, 50);
			printw("   ");
			attrset(COLOR_PAIR(7));
			for(j = 0; j < 8; j++)
				printw("     ");
			printw(" ");	
			attrset(COLOR_PAIR(5) | A_BOLD);	
			printw("   ");	
			k++;
		}	
	
	attrset(COLOR_PAIR(5) | A_BOLD);
	move(k,52);
	for(i = 0; i < 7; i++) 
		printw("  --  ");	
	k++;
	printw(" ");
	move(k,53);
	printw(" ");
	for(i = 0; i < 8; i++)  
		printw("  %d  ", i);	
	k++;
	printw("\n");
	printw("\n");
}

void save(int t, int type) {
	clear();
	int i, j;
	i = 0; 
	j = 0;
	
	char s[5];
	printw("Type the name you want to keep for your saved game\n");
	scanw("%s", s);
	refresh();
	
	char *q = malloc(sizeof(char)*20);
	q = strcat(q, "Save/");
	q = strcat(q, s);
	FILE *f;
	f = fopen(q, "a+");
	while(1) {	
		fprintf(f, "%d", a[j++][i]);
		fprintf(f, "%c", ' ');
		if (j == 8) {
			j = 0;
			i++;
		}
		if(i == 8) 
			break;	 
	}
	fprintf(f, "%c", ' ');
	if(t == 1)
		fprintf(f, "%d", 2);
	else 
		fprintf(f, "%d", 1);	
	fprintf(f, "%c", ' ');
	fprintf(f, "%d", type);
	//Gotta save the list of names of saved files in another list
	fclose(f);
	
	f = fopen(REF, "a+");
	fprintf(f, "%s", s);
	fprintf(f, "%c", '\n');
	fclose(f);
	
	getch();
	menu();
}

void load() {
	
	clear();
	int i, j, z;
	i = 0;
	j = 0;
	
	FILE *f, *p;
	f = fopen(REF, "r");
	char s[10];
	char h[10];
			
	while(fscanf(f, "%s", h) != EOF)
		printw("%s\n", h);
	
	printw("Which game you wanna load??\n");
	scanw("%s", s);
	refresh();
	
	char *q = malloc(sizeof(char) * 20);
	q = strcpy(q, "Save/");
	q = strcat(q, s);
	
	p = fopen(q, "r");
	
	while((fscanf(p, "%d", &a[j++][i])) != EOF) {
		if (j == 8) {
			j = 0;
			i++;
		}
		if(i == 8) 
			break;
	}
	fscanf(p, "%d", &t);
	fscanf(p, "%d", &z);
	fclose(p);
	fclose(f);
	getch();
	clear();
	printb();
	if(z == 1) 
		vs_human();
	else if(z == COMP1)
		vs_comp1();
	else if(z == COMP2)
		vs_comp2();
	else if(z == COMP3)
		vs_comp3();				
}		

void inv_print() {
		int x, y, inv;
		clear();
		printb();
		move(6, 0);
		//printw("\n");
		init_pair(1, COLOR_YELLOW, COLOR_BLUE);
		attrset(COLOR_PAIR(1));	
		printw("INVALID MOVE PLAY AGAIN");
		move(7, 0);
		if(t == 2) {
			printw("Player 2's turn");	
			attron(COLOR_PAIR(4) | A_BOLD);
			printw(" O ");
			move(8, 0);
			scanw("%d%d", &x, &y);
			if(x == -1)
				save(t, r3);
			else if(x == -2)
				menu();	
			attroff(COLOR_PAIR(4) | A_BOLD);		
			inv = valid(x,y,2, PLAY);
			if(inv == 0) 
				inv_print();
		}
		else {
			printw("Player 1's turn");
			attron(COLOR_PAIR(3) | A_BOLD);
			printw(" O ");
			move(8, 0);
			scanw("%d%d", &x, &y);
			if(x == -1)
				save(t, r3);
			else if(x == -2)
				menu();	
			attroff(COLOR_PAIR(3) | A_BOLD);		
			inv = valid(x,y,1, PLAY);
			if(inv == 0)
				inv_print();
			attroff(COLOR_PAIR(1));
		}	
}	

void endresult() {
	
	int i,j, ct1, ct2;
	ct1 = 0;
	ct2 = 0;
				
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			if(a[i][j] == 1)
				ct1++;
			else
				ct2++;	
		}
	}
	
	if(ct1 > ct2) 
		printf("Player 1 wins\n");
	else if(ct2 > ct1)
		printf("Player 2 wins\n");
	else
		printf("It's a draw\n");
	
	menu();	
}				  
  					
void vs_human() {
	int i, tog = 0;
	int x, y, ty, inv;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, b, c;
		c = -1;
		if(t == 1)
			ty = 2;
		else
			ty = 1;	
			
		for(d = 0; d < 8; d++) {
			for(b = 0; b < 8; b++) {
				if(a[d][b] == 0)
					c = valid(d, b, ty, VMOV);
				if(c == 1) 
					break;
			}	
			if(c == 1)	
				break;
		}
		
		if(c == -1) {
			tog++;
			printw("NO VALID MOVES AVAIL\n");
			if(t == 2)
				t = 1;
			else
				t = 2;
			if(tog == 2)		
				endresult();		
		}	
		else
			tog = 0;
			
		if(t == 1) {
			printw("Player 2's turn\n");
			t = 2;
		}	
		else {
			printw("Player 1's turn\n");
			t = 1;	
		}	
		scanw("%d%d", &x, &y);
		if(x == -1) {
			save(t, 1);
			break;
		}	
		else if (x == -2)
			menu();
			
		inv = valid(x,y,t, PLAY);
		if(inv == 0) 
			inv_print();
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
		
		
	}
	endresult();
}		

void vs_comp1() {

	//First need var for coordinates
	//printw("Hi");
	int x, y, ty, inv;
	int i, tog = 0;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, b, c;
		c = -1;
		if(t == 1) 
			ty = 2;
		else
			ty = 1;
				
		for(d = 0; d < 8; d++) {
			for(b = 0; b < 8; b++) {
				if(a[d][b] == 0)
					c = valid(d, b, ty, VMOV);
				if(c == 1) 
					break;
			}	
			if(c == 1)	
				break;
		}
		
		if(c == -1) {
			tog++;
			printw("NO VALID MOVES AVAIL\n");
			if(t == 2)
				t = 1;
			else 
				t = 2;
				
			if(tog == 2) 
				endresult();		
		}
		else 
			tog = 0;
		c = -1;
		
		if(t == 2) {
			printw("Human's turn\n");
			scanw("%d%d", &x, &y);
			t = 1;
			if(x == -1) {
				save(t, COMP1);
				break;
			}
			else if (x == -2)
				menu();
					
			inv = valid(x,y,t, PLAY);
			if(inv == 0) 
				inv_print();
		}
		else {
			t = 2;
			for(d = 0; d < 8; d++) {
				for(b = 0; b < 8; b++) {
					if(a[d][b] == 0) 
						c = valid(d, b, t, COMP1);
					if(c == 1) 
						break;
				}	
				if(c == 1) {
					napms(1000);
					valid(d, b, t, PLAY);	
					break;
				}	
			}
			if(c == -1) {
				tog++;
				if(tog == 2)
					endresult();
			}		
		}
		
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
	}
	endresult();
}		
				
void vs_comp2() {

	int x, y, ty, inv;
	int i, tog = 0;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, e, c;
		c = -1;
		if(t == 1) 
			ty = 2;
		else
			ty = 1;
				
		for(d = 0; d < 8; d++) {
			for(e = 0; e < 8; e++) {
				if(a[d][e] == 0)
					c = valid(d, e, ty, VMOV);
				if(c == 1) 
					break;
			}	
			if(c == 1)	
				break;
		}
		
		if(c == -1) {
			tog++;
			printw("NO VALID MOVES AVAIL\n");
			if(t == 2)
				t = 1;
			else 
				t = 2;
				
			if(tog == 2) 
				endresult();		
		}
		else
			tog = 0;
		c = -1;
		
		if(t == 2) {
			printw("Human's turn\n");
			scanw("%d%d", &x, &y);
			t = 1;
			if(x == -1) {
				save(t, COMP2);
				break;
			}	
			else if (x == -2)
				menu();
				
			inv = valid(x,y,t, PLAY);
			if(inv == 0)
				inv_print();
		}
		else {	
			t = 2;
			for(x = 0; x < 8; x ++) 
				for(y = 0; y < 8; y++)
					b[x][y] = 0;
			
			for(x = 0; x < 8; x ++) 
				for(y = 0; y < 8; y++) 
					valid(x, y, t, COMP2);			
	
			int max = -1;
			int max_x = -1; 
			int max_y = -1;
			for(x = 0; x < 8; x ++) { 
				for(y = 0; y < 8; y++) { 
					if(max < b[x][y]) { 
						max = b[x][y];
						max_x = x;
						max_y = y;
					}
				}
			}	
			if(max == -1) {
				tog++;
				if(tog == 2)
					endresult();
			}		
			napms(2000);
			valid(max_x, max_y, t, PLAY);
		}		
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
	}
	endresult();
}			
				
void vs_comp3() {
	
	int k, j;
	int x, y, ty;
	int i, tog = 0;
	int inv;
	
	// Make the priority table ready to refer
	FILE *f;
	f = fopen(PT, "r");
	for(k = 0; k < 8; k++)
		for(j = 0; j < 8; j++)
			fscanf(f, "%d", &b[j][k]);
	
	g = malloc(sizeof(prior));
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, e, c;
		c = -1;
		if(t == 1) 
			ty = 2;
		else
			ty = 1;
				
		for(d = 0; d < 8; d++) {
			for(e = 0; e < 8; e++) {
				if(a[d][e] == 0)
					c = valid(d, e, ty, VMOV);
				if(c == 1) 
					break;
			}	
			if(c == 1)	
				break;
		}
		
		if(c == -1) {
			tog++;
			printw("NO VALID MOVES AVAIL\n");
			if(t == 2)
				t = 1;
			else 
				t = 2;
				
			if(tog == 2) 
				endresult();		
		}
		else
			tog = 0;
		c = -1;
		
		if(t == 2) {
			printw("Human's turn\n");
			scanw("%d%d", &x, &y);
			t = 1;
			if(x == -1) {
				save(t, COMP3);
				break;
			}	
			else if (x == -2)
				menu();
				
			inv = valid(x,y,t, PLAY);
			if(inv == 0)
				inv_print();
		}
	//COMP S TURN
	// Now call the func to check all valid moves using st COMP3
		else {
			g->x = 0;
			g->y = 0;
			g->i = 0;
			g->p = -1;
			t = 2;
			for(k = 0; k < 8; k++) {
				for(j = 0; j < 8; j++) { 
					if(a[i][j] == 0) {
						if(a[k][j] == 0)
							valid(k, j, t, COMP3);
					}		
				}
			}	
			if(g->p == -1) {
				tog++;
				if(tog == 2)
					endresult();
			}		
			napms(3000);
			valid(g->x, g->y, t, PLAY);
		}	
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
	}
	endresult();
}			
				

		
	
	
	
	
	
	
	
	
	
	
	





