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
#include <signal.h>

#include "colors.h"
#include "settings.h"
#include "reader.h"
#include "printer.h"
#include "style.h"

void safeEnd (int)
{
	printf(CRES);
	printf(END);

	exit(1);
}

int main (const int argc, const char** argv)
{
	signal(SIGINT, safeEnd);

	#ifdef _WIN32
		system("color");
	#endif

	printf(SETUP);
	printf(B_C);
	printf(REFRESH);

	Settings* s = gset(argc, argv);

	if (!s->error)
	{
		char* data = reader(s);

		if (!s->error)
		{
			printer(data);
		}

		free(data);
	}

	free(s->input);
	free(s);

	printf(CRES);
	printf(END);

	return 0;
}
