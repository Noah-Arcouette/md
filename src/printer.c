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

	for (int i = 0; data[i]!='\0'; i++)
	{
		char j = data[i];

		switch (j)
		{
			case '#':
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
				break;

			case '-':
				if (LI)
					printf("\t");

				printf("%s%s -", CBOLD, LIST_C);

				printf("%s%s%s", CRES, DEF_C, B_C);
				break;

			case '\n':
				printf("%s%s%s\n", CRES, DEF_C, B_C);
				hcount = 0;

				break;

			default:
				printf("%c", j);
				break;
		}
	}
}
