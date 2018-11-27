#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int value)
{
	char *str;
	long n;
	int sign;
	int i;
	int base = 10;


	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;

	while ((n /= base) >= 1)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

int main(void)
{
	printf("%s\n", ft_itoa(-12345));
}