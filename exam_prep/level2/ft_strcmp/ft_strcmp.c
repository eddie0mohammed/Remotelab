#include <string.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] - s2[i] == 0)
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int main(void)
{
	char a[] = "hello";
	char b[] = "hi";
	printf("%d\n", ft_strcmp(a, b));
	printf("%d\n", strcmp(a, b));

	return (0);

}