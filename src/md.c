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
				outputsz+=4;
				output = realloc(output, outputsz);
				strcat(output, "\x1b[4m");
			#endif

			outputsz+=4;
			output = realloc(output, outputsz);
			strcat(output, CBOLD);

			switch (hcount)
			{
				case 0:
					outputsz+=sizeof(H1_C);
					output = realloc(output, outputsz);
					strcat(output, H1_C);
					break;
				case 1:
					outputsz+=sizeof(H2_C);
					output = realloc(output, outputsz);
					strcat(output, H2_C);
					break;
				default: 
					outputsz+=sizeof(H3_C);
					output = realloc(output, outputsz);
					strcat(output, H3_C);
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
			outputsz += 4 + sizeof(UL_C) + 1 + sizeof(DEF_C) + sizeof(B_C);
			output = realloc(output, outputsz);
			strcat(output, CBOLD UL_C);
			strncat(output, &C, 1);
			strcat(output, DEF_C B_C);

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
				outputsz += 4;
				output = realloc(output, outputsz);
				#ifdef I
					strcat(output, "\x1b[3m");
				#else
					strcat(output, CBOLD);
				#endif
			}
			else
			{
				outputsz += 4 + sizeof(DEF_C) + sizeof(B_C);
				output = realloc(output, outputsz);
				strcat(output, CRES DEF_C B_C);
			}

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
				currentFG = realloc(currentFG, (sizeof(HL_C)+1) * sizeof(char));
				currentBG = realloc(currentBG, (sizeof(HLB_C)+1) * sizeof(char));

				strcpy(currentFG, HL_C);
				strcpy(currentBG, HLB_C);
			}
			else
			{
				currentFG = realloc(currentFG, (sizeof(DEF_C)+1) * sizeof(char));
				currentBG = realloc(currentBG, (sizeof(B_C)+1) * sizeof(char));
			
				strcpy(currentFG, DEF_C);
				strcpy(currentBG, B_C);
			}
		}

		flags ^= STOP;


		if (!(flags & TICK))
		{
			outputsz += sizeof(HLB_C) + sizeof(HL_C) + 1;
			output = realloc(output, outputsz);
			strcat(output, HLB_C HL_C "`");
		}
		else
		{
			outputsz += sizeof(DEF_C) + sizeof(B_C) + 1 + 4;
			output = realloc(output, outputsz);
			strcat(output, "`" CRES DEF_C B_C);
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
			outputsz += sizeof(CLU_C) + 1;
			output = realloc(output, outputsz);
			strcat(output, CLU_C "[");

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
			outputsz += sizeof(CLU_C) + 1 + 4 + sizeof(DEF_C) + sizeof(B_C);
			output = realloc(output, outputsz);
			strcat(output, CLU_C "]" CRES DEF_C B_C);

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
			outputsz += 1 + sizeof(CLC_C);
			output = realloc(output, outputsz);
			strcat(output, CLC_C);
			strncat(output, &C, 1);

			break;
		}

		goto dump;

	case '\n':
		if (!(flags & SKIP))
		{
			hcount ^= hcount;
		}

		outputsz += 1 + 4 + strlen(currentFG) + strlen(currentBG);
		output = realloc(output, outputsz);
		strcat(output, CRES);
		strcat(output, currentFG);
		strcat(output, currentBG);
		strcat(output, "\n");

		flags |= NEWLINE;

		break;

	case ' ':
		goto dump;

	default:
		flags &= ~NEWLINE;

		dump:
			output = realloc(output, ++outputsz);
			strncat(output, &C, 1);
			break;
}
		