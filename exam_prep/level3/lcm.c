#include <stdio.h>

unsigned int	hcf(unsigned int a, unsigned int b)
{
	if (a == b)
		return (a);
	if (a > b)
		return hcf(a - b, b);
	else
		return hcf(a, b - a);
}


unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return (0);

	int res = (a * b)/ (hcf(a, b));
	return (res);
}

int main(void)
{
	printf("%d\n", lcm(0, 209));
	return 0;
}