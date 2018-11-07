#include <stdio.h>

char *ft_strrrev(char *str)
{
	int i;
	int len;
	int k;
	char temp;

	i = 0;
	while (str[i])
		i++;
	i--;
	len = i;
	k = i;
	i = 0;
	while (i <= (len / 2))
	{
		temp = str[i];
		str[i] = str[k];
		str[k] = temp;
		i++;
		k--;
	}
	return (str);

}

int main()
{
	char a[] = "hexloi";
	printf("%s\n", ft_strrrev(a));


	return (0);
}







