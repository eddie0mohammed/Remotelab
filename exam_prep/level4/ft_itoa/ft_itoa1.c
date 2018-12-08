#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int num)
{
	char *str;
	int base = 10;
	int i;
	int sign;
	long n;

	n = (num < 0) ? -(long)num : num;
	sign = (num < 0 && base == 10) ? -1 : 1;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	n = (num < 0) ? -(long)num : num;
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);

}

int main(void)
{
	printf("%s\n", ft_itoa(-12345));
	return 0;
}