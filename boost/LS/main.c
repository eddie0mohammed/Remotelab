#include "ft_header.h"
#include "structs.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>


int		main(int argc, char **argv)
{
	int 	*flags;

	if (argc >= 2)
	{
		//check for flags -lart (see ft_check_flags)
		flags = check_flags(argc, argv);
		if (flags[0] == 1 || flags[1] == 1 || flags[2] == 1 || flags[3] == 1) 
		{	//flags present => increment argv => continue;
			++(*argv);
		}
		// ls file1.txt (only 1 argument with no flags)
		if (argv[1] && argv[1][0] != '-')
			ft_argc_1(argv[1]);








	}
	else
	{
		ft_argc_1(".");
	}


	//printf("%d %d %d %d\n", flags[0], flags[1] , flags[2], flags[3]);

	return (0);
}







/*
line 16:
consider flag[0] = 1 separately:
else if (flag[0] == l)
{
	++(*argv);
	ft_argv_flag_l(argv);
}
*/