project: b s l c
	gcc  b s l c -o project -lncurses
b: basic.h basic.c impdef.h
	gcc -c basic.c -o b
s: basic.h sam1.c impdef.h
	gcc -c sam1.c -o s
l: start.c start.h impdef.h
	gcc -c start.c -o l
c: stack.c stack.h impdef.h
	gcc -c stack.c -o c
