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
#include "printer.h"

#include "main.h"

#define IN   		0x01
#define SKIP 		0x02
#define NEWLINE 	0x04
#define TICK 		0x08
#define LIST 		0x10
#define STOP 		0x20

void printer (char* data, Settings* s)
{
	printf("%s%s%s", CRES, DEF_C, B_C);

	uint8_t flags = 0x00;

	uint8_t hcount = 0;

	char* currentFG = malloc(strlen(DEF_C)+1 * sizeof(char));
	strcpy(currentFG, DEF_C);

	char* currentBG = malloc(strlen(B_C)+1 * sizeof(char));
	strcpy(currentBG, B_C);

	for (int i = 0; data[i]!='\0'; i++)
	{
		char j = data[i];

		switch (j)
		{
			case '#':
				if (
					!(flags & STOP) && 
					!(flags & SKIP) && 
					(
						(flags & NEWLINE) || 
						i == 0 || 
						hcount != 0
					))
				{
					if (HU)
						puts("\x1b[4m");

					puts(CBOLD);

					switch (hcount)
					{
						case 0:
							printf("%s", H1_C);
							break;
						case 1:
							printf("%s", H2_C);
							break;
						default: 
							printf("%s", H3_C);
							break;
					}

					hcount++;
				}
				else
				{
					printf("#");
				}

				flags = (flags & ~NEWLINE);
				break;

			case '>':
			case '-':
				if (
					!(flags & STOP) && 
					!(flags & SKIP) && 
					(
						data[i-2] == '\n' || 
						data[i-1] == '\n'
					))
				{
					if (LI)
						printf("\t");

					printf("%s%s %c%s%s%s", 
						CBOLD, 
						LIST_C, 
						j,
						CRES,
						B_C, 
						DEF_C
					);
				}
				else
				{
					printf("%c", j);
				}

				flags = (flags & ~NEWLINE);
				break;

			case '=':
				if (
					!(flags & STOP) && 
					!(flags & SKIP) && 
					(flags & NEWLINE)
				)
				{
					printf("%s%s=", CBOLD, UL_C);

					printf("%s%s%s", CRES, DEF_C, B_C);
				}
				else
				{
					printf("=");
				}

				break;

			case '*':
				if (
					!(flags & STOP) && 
					!(flags & SKIP)
				)
				{
					if (data[i-1] == '*')
					{
						printf("%s", CBOLD);
					}

					if (!(flags & IN))
					{
						if (I)
							printf("\x1b[3m");
					}
					else
						printf("%s%s%s", CRES, DEF_C, B_C);

					flags = (flags ^ IN);
				}
				else
				{
					printf("*");
				}

				flags = (flags & ~NEWLINE);
				break;

			case '`':
				if (data[i-2] == '`')
				{
					flags = (flags | (TICK * ((flags & SKIP) > 0)));
					flags = (flags ^ SKIP);

					if ((flags & SKIP))
					{
						currentFG = realloc(currentFG, strlen(HL_C)+1 * sizeof(char));
						currentBG = realloc(currentBG, strlen(HLB_C)+1 * sizeof(char));
					
						strcpy(currentFG, HL_C);
						strcpy(currentBG, HLB_C);
					}
					else
					{
						currentFG = realloc(currentFG, strlen(DEF_C)+1 * sizeof(char));
						currentBG = realloc(currentBG, strlen(B_C)+1 * sizeof(char));
					
						strcpy(currentFG, DEF_C);
						strcpy(currentBG, B_C);
					}
				}

				flags = (flags ^ STOP);


				if (!(flags & TICK))
				{
					printf("%s%s`", HLB_C, HL_C);
				}
				else
				{
					printf("`%s%s%s", CRES, DEF_C, B_C);
				}

				if (flags & SKIP)
					flags = (flags & ~TICK);
				else
					flags = (flags ^ TICK);

				flags = (flags & ~NEWLINE);
				break;

			case '[':
				if (
					!(flags & STOP) && 
					!(flags & SKIP)
				)
				{
					printf("%s[", CLU_C);

					flags = (flags | LIST);
				}
				else
					printf("[");

				flags = (flags & ~NEWLINE);
				break;
			case ']':
				if (
					!(flags & STOP) && 
					(flags & LIST) && 
					!(flags & SKIP)
				)
				{
					printf("%s]%s%s%s", CLU_C, CRES, DEF_C, B_C);
				
					flags = (flags & ~LIST);
				}
				else
					printf("]");

				flags = (flags & ~NEWLINE);
				break;

			case 'x':
			case 'X':
				if (
					!(flags & STOP) && 
					(flags & LIST) && 
					!(flags & SKIP)
				)
				{
					printf("%s%c", CLC_C, j);
				}
				else
				{
					printf("%c", j);
				}

				flags = (flags & ~NEWLINE);
				break;

			case '\n':
				if (!(flags & SKIP))
				{
					hcount = 0;
				}

				printf("\n%s%s%s", CRES, currentFG, currentBG);
				flags = (flags | NEWLINE);

				break;

			case ' ':
				printf(" ");

				break;

			default:
				printf("%c", j);
				flags = (flags & ~NEWLINE);
				break;
		}
	}

	free(currentBG);
	free(currentFG);
}
