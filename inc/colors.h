/*
	      _____           ___
	     /  _  \         /  /
	    /  / \  \       /  /
	   /  /___\  \     /  /
	  /  ______\  \   /  /
	 /  /       \  \_/  /
	/__/         \_____/

	By: Noah Arcouette

*/
#ifndef __BASH_COLOR_CODES__
#define __BASH_COLOR_CODES__
// foreground
#define CRES 	"\x1b[0m"
#define CBOLD	"\x1b[1m"

#define FG_ANSI(color) "\x1b[38;5;" #color "m"
#define BG_ANSI(color) "\x1b[48;5;" #color "m"

#define FG_RGB(R, G, B) "\x1b[38;2;" #R ";" #G ";" #B "m"
#define BG_RGB(R, G, B) "\x1b[48;2;" #R ";" #G ";" #B "m"

#define END     "\x1b[?25h\x1b[?47l"
#define REFRESH "\x1b[2J\x1b[H"
#define SETUP   "\x1b[?25l\x1b[?47h"

#endif // __BASH_COLOR_CODES__
