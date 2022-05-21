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

#include <sys/poll.h>

int main (const int argc, const char** argv)
{
	signal(SIGINT, safeEnd);

	#ifdef _WIN32
		system("color");
	#endif

	struct pollfd fds;
  fds.fd = 0;
  fds.events = POLLIN;

  poll(&fds, 1, 0);

	Settings* s = gset(argc, argv);

	if (poll(&fds, 1, 0) == 1)
	{
		s->input = realloc(s->input, 11 * sizeof(char));
		strcpy(s->input, "/dev/stdin");
	}

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
