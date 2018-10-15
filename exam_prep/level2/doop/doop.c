#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 4)
	{
		if (!argv[1] || !argv[2] || !argv[3])
			return (0);
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		else if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1]) - atoi(argv[3])));
		else if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		else if (argv[2][0] == '%')
		printf("%d", (atoi(argv[1]) % atoi(argv[3])));
		else if (argv[2][0] == '*')
			printf("%d", ((atoi(argv[1])) * (atoi(argv[3]))));

	}
	printf("\n");
	return (0);
}