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

#ifdef _WIN32
#	define HELP " C:\\ProgramData\\md\\CommandLine.md"
#else
#	define HELP " /usr/doc/md/CommandLine.md"
#endif

Settings* gset (const int argc, const char** argv)
{
	Settings* s = malloc(sizeof(Settings));
	s->error = 0;

	s->input = malloc(1 * sizeof(char));
	s->input[0] = 0;

	char* self = malloc((strlen(argv[0])+1 + strlen(HELP)) * sizeof(char));
	strcpy(self, argv[0]);
	strcat(self, HELP);

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

					#ifdef _WIN32
						system("type C:\\ProgramData\\md\\face");
					#else
						system("cat /usr/doc/md/face");
					#endif
					break;

				default:
					s->error = 1;

					printf("%s%sError: %sUnknown option `%s'.\n",
						CBOLD,
						ERROR_C,
						DEF_C,
						argv[i]
					);

					break;
			}
		}
		else
		{
			s->input = realloc(s->input, strlen(argv[i])+1);
			strcpy(s->input, argv[i]);
		}
	}

	free(self);

	return s;
}
