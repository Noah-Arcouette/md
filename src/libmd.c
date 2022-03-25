#include "md.h"
#include "printer.h"
#include <stdio.h>
#include "colors.h"

void mdout (char* data)
{
	#ifdef _WIN32
		system("color");
	#endif

	printer(data);

	printf(CRES);
}
