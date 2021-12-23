#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "settings.h"
#include "reader.h"
#include "main.h"

char* reader (Settings* s)
{
	size_t datasz = 1;
	char* data = malloc(datasz * sizeof(char));
	strcpy(data, "");

	char* line = NULL;
	size_t len = 0;

	FILE* fp = fopen(s->input, "r");

	if (fp == NULL)
	{
		s->error = 1;

		printf("%sError: %sFile `%s' cannot be opened.\n",
			ERROR_C,
			DEF_C,
			s->input
		);

		return NULL;
	}

	while ((getline(&line, &len, fp)) != -1)
	{
		datasz += len;

		data = realloc(data, datasz * sizeof(char));
		strcat(data, line);
	}

	if (line)
		free(line);

	fclose(fp);

	return data;
}
