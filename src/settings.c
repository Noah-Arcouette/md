#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "settings.h"
#include "main.h"

Settings* gset (const int argc, const char** argv)
{
	Settings* s = malloc(sizeof(Settings));
	s->error = 0;

	s->input = malloc(1 * sizeof(char));
	strcpy(s->input, "");

	for (int i = 1; i<argc; i++)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
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
			s->input = realloc(s->input, sizeof(argv[i]));
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
