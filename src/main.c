#include <stdio.h>

#include "colors.h"

int main ()
{
	printf("%s%sHello, world!\n%s",
		CBOLD,
		FG_199,
		CRES
	);

	return 0;
}
