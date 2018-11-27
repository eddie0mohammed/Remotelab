#include <stdio.h>

int is_prime(int num)
{
	if (num < 0 || num == 0 || num == 1)
		return (0);
	int i = 2;
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