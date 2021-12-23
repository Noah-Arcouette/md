#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "settings.h"
#include "reader.h"

int main (const int argc, const char** argv)
{
	printf("%s", CBOLD);

	Settings* s = gset(argc, argv);

	if (!s->error)
	{
		char* data = reader(s);

		if (!s->error)
		{
			printf("%s\n", data);
		}

		free(data);
	}

	freeset(s);

	printf("%s", CRES);

	return 0;
}
