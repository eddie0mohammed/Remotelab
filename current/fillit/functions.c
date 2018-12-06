#include "header.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_get_size(t_list *begin_list)
{
	int size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

int		ft_get_nearest_square(int size)
{
	int min_size;

	min_size = 2;
	while ((min_size * min_size) < (size * 4))
	{
		min_size++;
	}
	return (min_size);
}