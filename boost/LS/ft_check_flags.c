#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int 	*check_flags(int argc, char **argv)
{
	static int 	flags[4];  	// flags[4] = {'l', 'a', 'r', 't'}
	int 		i;

	i = 0;
	while (i++ < 4)	//initialize all flags to 0
			flags[i] = 0;
	if (argc >= 2) // if more that one argument (ls -flag)
	{		
		i = 0;
		if (argv[1][i] && argv[1][0] == '-')
		{	// if only '-' as argument
			if (strlen(argv[1]) == 1 && argv[1][0] == '-')
			{
				printf("ls: %s: No such file or directory\n", argv[1]);
				exit(1);
			}
			i++;		
			if (strlen(argv[1]) >= 2)
			{
				while (argv[1][i])
				{
					// if (argv[1][1] == '-' && (strlen(argv[1]) == 2))
					// 	return (flags);
					if (argv[1][i] == 'l')
						flags[0] = 1;
					else if (argv[1][i] == 'a')
						flags[1] = 1;
					else if (argv[1][i] == 'r')
						flags[2] = 1;
					else if (argv[1][i] == 't')
						flags[3] = 1;
					//if illegal flags used
					else
					{
						printf("ls: illegal option -- %c\n", argv[1][i]);
						printf("usage: ls [-alrt] [file ...]\n");
						exit(1);
					}
					i++;
				}
			}
		}
	}
	return (flags);
}

