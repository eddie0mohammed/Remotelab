#include <stdio.h>

int 	is_prime(unsigned int num)
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

int		main(void)
{
	int i;
	for (i = 0; i <= 100; i++)
	{
		if (is_prime(i))
			printf("%d ", i);
	}
	printf("\n");
	return (0);
}