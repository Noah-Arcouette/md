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

	this file is for users running on a TTY session

*/

#include <advo.h>

#define ERROR_C	FG_ANSI(1) // error color

#define DEF_C	FG_ANSI(7) // default color
#define B_C 	""   // background color

#define H1_C 	FG_ANSI(5) // header 1 color
#define H2_C 	FG_ANSI(4) // header 2 color
#define H3_C 	FG_ANSI(6) // header 3 color

// #define HU // header underline

#define CLC_C 	FG_ANSI(6) // check list checked
#define CLU_C 	FG_ANSI(4) // check list unchecked

#define UL_C FG_ANSI(1) // under line and list color

// #define LI // list indent

#define HLB_C 	 "" // highlight background color
#define HL_C 	 FG_ANSI(2)  // highlight foreground color

#define OP_C  FG_ANSI(1) // operator color
#define INT_C FG_ANSI(5)  // integer color
#define PAR_C FG_ANSI(4)  // parentheses color
#define STR_C FG_ANSI(3) // string color

#define ADVO

#define TEXTC COLOR_ANSI_FG(7)
#define BOXC  COLOR_ANSI_FG(4)

#define NAME "TTY-Support"
#define BY   "Noah Arcouette"

// #define BOX_TYPE_CIR
// #define BOX_TYPE_SBOX
#define BOX_TYPE_BOX

// #define I // italicize
