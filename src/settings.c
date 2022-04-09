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
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#ifdef ADVO
#	include <advo.h>
#endif

#include "settings.h"
#include "colors.h"
#include "style.h"

#ifdef _WIN32
#	define HELP "C:\\ProgramData\\md\\CommandLine.md"
#else
#	define HELP "/usr/doc/md/CommandLine.md"
#endif

Settings* gset (const int argc, const char** argv)
{
	Settings* s = malloc(sizeof(Settings));
	s->error = 0;

	#ifndef _WIN32
		s->input = malloc(11 * sizeof(char));
		strcpy(s->input, "/dev/stdin");
	#else
		s->input = malloc(1 * sizeof(char));
		s->input[0] = 0;
	#endif

	register uint8_t kill = 0;

	for (int i = 1; (i<argc && !kill); i++)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				case 'h':
					s->input = realloc(s->input, sizeof(HELP) * sizeof(char));
					strcpy(s->input, HELP);

					kill = 1;

					break;

				case 'f':
					s->error = 1;

					kill = 1;

					#ifdef _WIN32
						system("type C:\\ProgramData\\md\\face");
					#else
						system("cat /usr/doc/md/face");
					#endif
					break;

				default:
					s->error = 1;

					kill = 1;

					printf(CBOLD ERROR_C "Error: " DEF_C "Unknown option `%s'.\n",
						argv[i]
					);

					break;
			}
		}
		else
		{
			s->input = realloc(s->input, strlen(argv[i])+1);
			strcpy(s->input, argv[i]);
		}
	}

	char* output = malloc(
		sizeof("FILE:  ") + strlen(s->input) + 1 +
		sizeof("STYLE: ") + sizeof(NAME) +
		sizeof(" By: ") + sizeof(BY) + 1
		);
	strcpy(output, "FILE:  ");
	strcat(output, s->input);
	strcat(output, "\n");
	strcat(output, "STYLE: " NAME " By: " BY "\n");

	#ifdef ADVO
		struct Color box  = BOXC;
		struct Color text = TEXTC;

		printf(B_C);


		#ifdef BOX_TYPE_CIR
			cirText(output, box, text);
		#elif defined BOX_TYPE_SBOX
			sboxText(output, box, text);
		#elif defined BOX_TYPE_BOX
			boxText(output, box, text);
		#endif
	#endif

	return s;
}
