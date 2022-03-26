/*
	      _____           ___
	     /  _  \         /  /
	    /  / \  \       /  /
	   /  /___\  \     /  /
	  /  ______\  \   /  /
	 /  /       \  \_/  /
	/__/         \_____/


	This file was made for a Noah Arcouette product.
	https://github.com/Noah-Arcouette

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "settings.h"
#include "colors.h"
#include "printer.h"

#include "style.h"

#define IN   		0b1
#define SKIP 		0b10
#define NEWLINE 	0b100
#define TICK 		0b1000
#define LIST 		0b10000
#define STOP 		0b100000

#define INSTR       0b1000000
#define BACKSLASH   0b10000000

#define C data[i]

void printer (char* data)
{
	printf(CRES DEF_C B_C);

	register uint8_t flags = 0x00;

	register uint8_t hcount = 0;

	register char hold;

	char* currentFG = malloc(sizeof(DEF_C) * sizeof(char));
	strcpy(currentFG, DEF_C);

	char* currentBG = malloc(sizeof(B_C) * sizeof(char));
	strcpy(currentBG, B_C);

	for (register int i = 0; data[i]!='\0'; i++)
	{
		#include "syntax.c"		
		#include "md.c"
	}

	free(currentBG);
	free(currentFG);

	printf("\n" CRES);
}
