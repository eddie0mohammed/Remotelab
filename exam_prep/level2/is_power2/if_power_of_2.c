#include <stdio.h>
#include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	if (n % 2 == 0)	//if even
	{
		while (n % 2 == 0) 
			n = n / 2;
		if (n == 1)
			return (1);
		
	}
	return (0);
}

int		main(int argc, char **argv)
{
	printf("%d\n", is_power_of_2(atoi(argv[1])));

	return (0);
}