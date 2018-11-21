#include <unistd.h>
#include <stdio.h>

unsigned int	print_bits(unsigned char octet)
{
	int i = 128;


	while (i > 0)
	{
		if (octet / i == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		octet %= i;
		i /= 2;
	}
	write(1, "\n", 1);
	return (0);
}
int	main(void)
{
	print_bits(1);
	print_bits(2);
	print_bits(4);
	print_bits(8);
	print_bits(16);
	print_bits(32);
	print_bits(64);
	print_bits(128);
	print_bits((unsigned char)256);
	return (0);
}