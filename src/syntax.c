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
if (flags & TICK || flags & SKIP)
{
	if (
		!(flags & INSTR) && 
		(C == '"' || C == '\'')
	)
	{
		hold = C;
		flags ^= INSTR;
	}
	else if (C == hold && !(flags & BACKSLASH))
	{
		flags ^= INSTR;
	}

	if (C == '\\' && !(flags & BACKSLASH))
	{
		flags |= BACKSLASH;
	}
	else
	{
		flags &= ~BACKSLASH;
	}

	if (flags & INSTR)
	{
		outputsz += sizeof(STR_C);
		output = realloc(output, outputsz);
		strcat(output, STR_C);
	}
	else
	{
		switch (C)
		{
			case '*':
			case '+':
			case '-':
			case '/':
			case '$':
			case '#':
			case ';':
			case ':':
			case '?':
			case '=':
			case '>':
			case '<':
			case '!':
			case '&':
			case '|':
			case '^':
			case '~':
			case '%':
				outputsz += sizeof(OP_C);
				output = realloc(output, outputsz);
				strcat(output, OP_C);
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '_':
			case '.':
			case ',':
			case '\\':
				outputsz += sizeof(INT_C);
				output = realloc(output, outputsz);
				strcat(output, INT_C);
				break;
			case '(':
			case ')':
			case '[':
			case ']':
			case '{':
			case '}':
				outputsz += sizeof(PAR_C);
				output = realloc(output, outputsz);
				strcat(output, PAR_C);
				break;
			case '"':
			case '\'':
				break;
			case ' ':
			default:
				outputsz += sizeof(HL_C);
				output = realloc(output, outputsz);
				strcat(output, HL_C);
				break;
		}
	}		
}
