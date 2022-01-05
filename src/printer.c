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

#include "settings.h"
#include "printer.h"

#include "main.h"

void printer (char* data, Settings* s)
{
	printf("%s%s%s", CRES, DEF_C, B_C);

	int hcount = 0;
	int in = 0;

	int skip = 0;

	int newLine = 0;

	int list = 0;
	int tick = 0;

	for (int i = 0; data[i]!='\0'; i++)
	{
		char j = data[i];

		switch (j)
		{
			case '#':
				if (!skip && (newLine || i == 0 || hcount != 0))
				{
					if (HU)
						printf("\x1b[4m");

					printf("%s", CBOLD);

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

				newLine = 0;
				break;

			case '>':
			case '-':
				if (!skip && (data[i-2] == '\n' || data[i-1] == '\n'))
				{
					if (LI)
						printf("\t");

					printf("%s%s %c", CBOLD, LIST_C, j);

					printf("%s%s%s", CRES, DEF_C, B_C);
				}
				else
				{
					printf("%c", j);
				}

				newLine = 0;
				break;

			case '=':
				if (!skip && newLine)
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
				if (!skip)
				{
					if (data[i-1] == '*')
					{
						printf("%s", CBOLD);
					}

					if (!in)
					{
						if (I)
							printf("\x1b[3m");
					}
					else
						printf("%s%s%s", CRES, DEF_C, B_C);

					in = !in;
				}
				else
				{
					printf("*");
				}

				newLine = 0;
				break;

			case '`':
				if (data[i-2] == '`')
				{
					tick = skip;

					skip = !skip;
				}


				if (!tick)
				{
					printf("%s%s`", HLB_C, HL_C);
				}
				else
				{
					printf("`%s%s%s", CRES, DEF_C, B_C);
				}

				if (skip)
					tick = 0;
				else
					tick = !tick;

				newLine = 0;
				break;

			case '[':
				if (!skip)
				{
					printf("%s[", CLU_C);

					list = 1;
				}

				newLine = 0;
				break;
			case ']':
				if (list && !skip)
				{
					printf("%s]%s%s%s", CLU_C, CRES, DEF_C, B_C);
				
					list = 0;
				}

				newLine = 0;
				break;

			case 'x':
			case 'X':
				if (list && !skip)
				{
					printf("%s%c", CLC_C, j);
				}
				else
				{
					printf("%c", j);
				}

				newLine = 0;
				break;

			case '\n':
				if (!skip)
				{
					printf("%s%s%s", CRES, DEF_C, B_C);
					hcount = 0;
				}

				printf("\n");
				newLine = 1;

				break;

			case ' ':
				printf(" ");

				break;

			default:
				printf("%c", j);
				newLine = 0;
				break;
		}
	}
}
