#include<ncurses.h>
#include<stdlib.h>
#include"start.h"

int main() {
	
	int x, y, i, t;
	initscr();
	
	/* Initializing some basic text color formats to be used throughout the program */
	
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(3, COLOR_BLUE, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_CYAN);
	init_pair(5, COLOR_YELLOW, COLOR_RED);
	init_pair(6, COLOR_RED, COLOR_YELLOW);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	
	call();
	flushinp();
	menu();
	
	clear();	
	getch();
	endwin();
	
	return 0;
}	
