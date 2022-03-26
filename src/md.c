switch (C)
{
	case '#':
		if (
			!(flags & STOP) && 
			!(flags & SKIP) && 
			(
				(flags & NEWLINE) || 
				i == 0 || 
				hcount != 0
			))
		{
			#ifdef HU
				printf("\x1b[4m");
			#endif

			printf(CBOLD);

			switch (hcount)
			{
				case 0:
					printf(H1_C);
					break;
				case 1:
					printf(H2_C);
					break;
				default: 
					printf(H3_C);
					break;
			}

			hcount++;

			flags &= ~NEWLINE;

			break;
		}

		flags &= ~NEWLINE;
		goto dump;

	case '=':
	case '-':
	case '>':
		if (
			!(flags & STOP) && 
			!(flags & SKIP) && 
			(flags & NEWLINE)
		)
		{
			printf(
				CBOLD
				UL_C
				"%c"
				CRES
				DEF_C
				B_C,
				C
			);

			break;
		}

		goto dump;

	case '*':
		flags &= ~NEWLINE;

		if (
			!(flags & STOP) && 
			!(flags & SKIP)
		)
		{
			if (!(flags & IN))
			{
				#ifdef I
					printf("\x1b[3m");
				#else
					printf(CBOLD);
				#endif
			}
			else
				printf(CRES DEF_C B_C);

			flags ^= IN;

			break;
		}

		goto dump;

	case '`':
		if (data[i-2] == '`')
		{
			flags |= (TICK * ((flags & SKIP) > 0));
			flags ^= SKIP;

			if ((flags & SKIP))
			{
				currentFG = realloc(currentFG, strlen(HL_C)+1 * sizeof(char));
				currentBG = realloc(currentBG, strlen(HLB_C)+1 * sizeof(char));
			
				strcpy(currentFG, HL_C);
				strcpy(currentBG, HLB_C);
			}
			else
			{
				currentFG = realloc(currentFG, strlen(DEF_C)+1 * sizeof(char));
				currentBG = realloc(currentBG, strlen(B_C)+1 * sizeof(char));
			
				strcpy(currentFG, DEF_C);
				strcpy(currentBG, B_C);
			}
		}

		flags ^= STOP;


		if (!(flags & TICK))
		{
			printf(HLB_C HL_C "`");
		}
		else
		{
			printf("`" CRES DEF_C B_C);
		}

		if (flags & SKIP)
			flags &= ~TICK;
		else
			flags ^= TICK;

		flags &= ~NEWLINE;
		break;

	case '[':
		flags &= ~NEWLINE;

		if (
			!(flags & STOP) && 
			!(flags & SKIP)
		)
		{
			printf(CLU_C "[");

			flags |= LIST;

			break;
		}
			
		goto dump;
	case ']':
		flags &= ~NEWLINE;

		if (
			!(flags & STOP) && 
			(flags & LIST) && 
			!(flags & SKIP)
		)
		{
			printf(CLU_C "]" CRES DEF_C B_C);
		
			flags &= ~LIST;

			break;
		}

		goto dump;

	case 'x':
	case 'X':
		flags &= ~NEWLINE;

		if (
			!(flags & STOP) && 
			(flags & LIST) && 
			!(flags & SKIP)
		)
		{
			printf(CLC_C "%c", C);

			break;
		}

		goto dump;

	case '\n':
		if (!(flags & SKIP))
		{
			hcount ^= hcount;
		}

		printf(CRES "%s%s\n", currentFG, currentBG);
		flags |= NEWLINE;

		break;

	case ' ':
		goto dump;

	default:
		flags &= ~NEWLINE;

		dump:
			printf("%c", C);
			break;
}
		