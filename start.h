
// Will have funtions that will enable the starting of the game in a decent way
#include"basic.h"

//Set of functioons for start

void fetch(char *);
void call();
void print();
void rec();
void lag();

/* Set of functions to be used for printing during gameplay */
void printb();
void inv_print();
void endresult();

// Functions related to menu
void menu();

// Save and load
void save(int, int);
void load();

/* Functions related to mode of game */
void vs_human();
void vs_comp1();
void vs_comp2(); 
void vs_comp3(); 
