#include <stdio.h>
#include <stdlib.h>

int is_prime(int num)
{
	int i = 2;
	if (num == 0 || num == 1)
		return (0);
	if (num == 2 || num == 3)
		return (1);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int i = 2;
	if (argc == 2)
	{
		int num = atoi(argv[1]);
		if (num <= 0)
			return (0);
		if (num == 1)
		{
			printf("1\n");
			return (0);
		}
		while (num > 1)
		{
			if (is_prime(i))
			{
				if (num % i == 0)
				{
					printf("%d", i);
					num /= i;
					if (num != 1)
						printf("*");
				}
				else
					i++;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}