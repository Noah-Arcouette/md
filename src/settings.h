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

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

typedef struct 
{
	char* input;
	int error;
} Settings;

// get settings

Settings* gset (const int, const char**);
void freeset 	(Settings*);

#endif // __SETTINGS_H__
