#include <stdio.h>
#include <stdlib.h>

unsigned int hcf(unsigned int a, unsigned int b)
{
	if (a == 0)
		return (b);
	if (b == 0)
		return (a);
	if (a == b)
		return (a);
	if (a > b)
		return (hcf(a - b, b));
	return (hcf(a, b -a));

}

int main(int argc, char	*argv[])
{
	if (argc == 3)
	{
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);

		int res = hcf(num1, num2);
		printf("%d", res);

		
		
			

	}
	printf("\n");
	return 0;
}