#include <stdio.h>

#include "colors.h"
#include "settings.h"

int main (const int argc, const char** argv)
{
	printf("%s", CBOLD);

	Settings* s = gset(argc, argv);

	if (!s->error)
	{
		printf("input: %s\n", s->input);
	}
	
	freeset(s);

	printf("%s", CRES);

	return 0;
}
