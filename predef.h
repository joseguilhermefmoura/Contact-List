#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _WIN32
#include <curses.h>
#else
#include <conio.h>
#endif
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ESC 27

int numberOfErrors = 0;

typedef int bool;
#define true 1
#define false 0

typedef struct element {
	char completeName[100];
	char emailAddress[100];
	char homeAddress[100];
	char dateOfBirth[10];
	char cellphoneNumber[15];
	char workphoneNumber[15];

	struct element *after;
	struct element *before;
} List;

typedef struct listControl {
	struct element *first;
	struct element *last;
	unsigned int lenght;
} ListControl;

void clearScreen(){
	#ifndef _WIN32
		system("clear");
	#else
		system("cls");
	#endif
}
