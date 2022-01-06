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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "settings.h"
#include "main.h"

size_t sizeofStr (const char* str)
{
	size_t size = 0;
	for (; str[size]!='\0'; size++)
	{}

	return (size+1); // include null byte
}

Settings* gset (const int argc, const char** argv)
{
	Settings* s = malloc(sizeof(Settings));
	s->error = 0;

	s->input = malloc(1 * sizeof(char));
	strcpy(s->input, "");

	char* self = malloc((sizeofStr(argv[0]) + sizeof(" /usr/doc/md/CommandLine.md")) * sizeof(char));
	strcpy(self, argv[0]);
	strcat(self, " /usr/doc/md/CommandLine.md");

	for (int i = 1; i<argc; i++)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				case 'h':
					s->error = 1;

					system(self);
					break;

				case 'f':
					s->error = 1;

					system("cat /usr/doc/md/face");
					break;

				default:
					s->error = 1;

					printf("%sError: %sUnknown option `%s'.\n",
						ERROR_C,
						DEF_C,
						argv[i]
					);

					break;
			}
		}
		else
		{
			s->input = realloc(s->input, sizeofStr(argv[i]));
			strcpy(s->input, argv[i]);
		}
	}

	return s;
}

void freeset (Settings* s)
{
	free(s->input);
	free(s);
}
