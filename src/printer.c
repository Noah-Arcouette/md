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

#define IN   		0b1
#define SKIP 		0b10
#define NEWLINE 	0b100
#define TICK 		0b1000
#define LIST 		0b10000
#define STOP 		0b100000

#define C data[i]

void printer (char* data, Settings* s)
{
	printf("%s%s%s", CRES, DEF_C, B_C);

	register uint8_t flags = 0x00;

	register uint8_t hcount = 0;

	char* currentFG = malloc(strlen(DEF_C)+1 * sizeof(char));
	strcpy(currentFG, DEF_C);

	char* currentBG = malloc(strlen(B_C)+1 * sizeof(char));
	strcpy(currentBG, B_C);

	for (int i = 0; data[i]!='\0'; i++)
	{
		switch (C)
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
					#ifdef HU
						printf("\x1b[4m");
					#endif

					printf(CBOLD);

					switch (hcount)
					{
						case 0:
							printf(H1_C);
							break;
						case 1:
							printf(H2_C);
							break;
						default: 
							printf(H3_C);
							break;
					}

					hcount++;

					flags &= ~NEWLINE;

					break;
				}

				flags &= ~NEWLINE;
				goto dump;

			case '>':
			case '-':
				flags &= ~NEWLINE;

				if (
					!(flags & STOP) && 
					!(flags & SKIP) && 
					(
						data[i-2] == '\n' || 
						data[i-1] == '\n'
					))
				{
					#ifdef LI
						printf("\t");
					#endif

					printf("%s%s %c%s%s%s", 
						CBOLD, 
						LIST_C, 
						C,
						CRES,
						B_C, 
						DEF_C
					);

					break;
				}

				goto dump;

			case '=':
				if (
					!(flags & STOP) && 
					!(flags & SKIP) && 
					(flags & NEWLINE)
				)
				{
					printf("%s%s=%s%s%s", 
						CBOLD, 
						UL_C, 
						CRES,
						DEF_C, 
						B_C
					);

					break;
				}

				goto dump;

			case '*':
				flags &= ~NEWLINE;

				if (
					!(flags & STOP) && 
					!(flags & SKIP)
				)
				{
					if (data[i-1] == '*')
					{
						printf(CBOLD);
					}

					if (!(flags & IN))
					{
						#ifdef I
							printf("\x1b[3m");
						#endif
					}
					else
						printf("%s%s%s", CRES, DEF_C, B_C);

					flags ^= IN;

					break;
				}

				goto dump;

			case '`':
				if (data[i-2] == '`')
				{
					flags |= (TICK * ((flags & SKIP) > 0));
					flags ^= SKIP;

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

				flags ^= STOP;


				if (!(flags & TICK))
				{
					printf("%s%s`", HLB_C, HL_C);
				}
				else
				{
					printf("`%s%s%s", CRES, DEF_C, B_C);
				}

				if (flags & SKIP)
					flags &= ~TICK;
				else
					flags ^= TICK;

				flags &= ~NEWLINE;
				break;

			case '[':
				flags &= ~NEWLINE;

				if (
					!(flags & STOP) && 
					!(flags & SKIP)
				)
				{
					printf("%s[", CLU_C);

					flags |= LIST;

					break;
				}
					
				goto dump;
			case ']':
				flags &= ~NEWLINE;

				if (
					!(flags & STOP) && 
					(flags & LIST) && 
					!(flags & SKIP)
				)
				{
					printf("%s]%s%s%s", CLU_C, CRES, DEF_C, B_C);
				
					flags &= ~LIST;

					break;
				}

				goto dump;

			case 'x':
			case 'X':
				flags &= ~NEWLINE;

				if (
					!(flags & STOP) && 
					(flags & LIST) && 
					!(flags & SKIP)
				)
				{
					printf("%s%c", CLC_C, C);

					break;
				}

				goto dump;

			case '\n':
				if (!(flags & SKIP))
				{
					hcount = 0;
				}

				printf("\n%s%s%s", CRES, currentFG, currentBG);
				flags |= NEWLINE;

				break;

			case ' ':
				goto dump;

			default:
				flags &= ~NEWLINE;

				dump:
					printf("%c", C);
					break;
		}
	}

	free(currentBG);
	free(currentFG);
}
