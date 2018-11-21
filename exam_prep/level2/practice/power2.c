#include <stdio.h>

int power2(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1 || n == 2)
		return (1);
	while (n % 2 == 0)
	{
		n /= 2;
	}
	if (n == 1)
		return (1);
	return (0);
}

int main(void)
{
	printf("%d\n", power2(128));
	return (0);
}