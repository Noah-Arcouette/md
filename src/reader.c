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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "settings.h"
#include "colors.h"
#include "reader.h"
#include "style.h"

char* reader (Settings* s)
{
	FILE* fp = fopen(s->input, "r");

	if (fp == NULL)
	{
		s->error = 1;

		printf(CBOLD ERROR_C "Error: " DEF_C "File `%s' cannot be opened.\n",
			s->input
		);

		return NULL;
	}

	register size_t datasz = 1;
	char* data = malloc(datasz * sizeof(char));
	data[0] = 0;

	char* line = NULL;
	size_t len;

	while ((getline(&line, &len, fp)) != -1)
	{
		datasz += len;

		data = realloc(data, datasz * sizeof(char));
		strcat(data, line);
	}

	free(line);

	fclose(fp);

	return data;
}
