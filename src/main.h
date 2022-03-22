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

#ifndef __MAIN_H__
#define __MAIN_H__	

#include "colors.h"

#define ERROR_C	FG_ANSI(9) // error color

#define DEF_C	FG_ANSI(253) // default color
#define B_C 	""   // background color

#define H1_C 	FG_ANSI(13) // header 1 color
#define H2_C 	FG_ANSI(14) // header 2 color
#define H3_C 	FG_ANSI(12) // header 3 color

// #define HU // header underline

#define CLC_C 	FG_ANSI(12) // check list checked
#define CLU_C 	FG_ANSI(14) // check list unchecked

#define UL_C FG_ANSI(202) // under line and list color

// #define LI // list indent

#define HLB_C 	 BG_ANSI(239) // highlight background color
#define HL_C 	 FG_ANSI(10)  // highlight foreground color

#define OP_C  FG_ANSI(202) // operator color
#define INT_C FG_ANSI(170)  // integer color
#define PAR_C FG_ANSI(33)  // parentheses color
#define STR_C FG_ANSI(214) // string color

// #define I // italicize

#endif // __MAIN_H__
