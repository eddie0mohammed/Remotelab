#include <stdio.h>

unsigned int	hcf(unsigned int a, unsigned int b)
{
	if (a == 0)
		return (b);
	if (b == 0)
		return (a);
	if (a == b)
		return (a);
	if (a > b)
		return (hcf(a - b, a));
	return (hcf(a, b - a));
}

int main(int argc, char const *argv[])
{
	printf("%d\n", hcf(70, 25));
	return 0;
}