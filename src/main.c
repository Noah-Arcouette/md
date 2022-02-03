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

#include "colors.h"
#include "settings.h"
#include "reader.h"
#include "printer.h"

int main (const int argc, const char** argv)
{
	#ifdef _WIN32
		system("color");
	#endif

	Settings* s = gset(argc, argv);

	if (!s->error)
	{
		char* data = reader(s);

		if (!s->error)
		{
			printer(data, s);
		}

		free(data);
	}

	free(s->input);
	free(s);

	printf("%s", CRES);

	return 0;
}
