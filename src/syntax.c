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
		printf(STR_C);
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
				printf(OP_C);
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
				printf(INT_C);
				break;
			case '(':
			case ')':
			case '[':
			case ']':
			case '{':
			case '}':
				printf(PAR_C);
				break;
			case '"':
			case '\'':
				break;
			case ' ':
			default:
				printf(HL_C);
				break;
		}
	}		
}
