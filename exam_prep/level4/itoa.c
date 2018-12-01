#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int value)
{
	char *str;
	int sign;
	int base = 10;
	int i;
	long n;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	n = (value < 0) ? -(long)value : value;
	str[i] = '\0';
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base; 
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

int main(int argc, char const *argv[])
{
	printf("%s\n", ft_itoa(112345));
	return 0;
}