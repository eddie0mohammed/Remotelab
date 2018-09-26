/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:53:33 by medun             #+#    #+#             */
/*   Updated: 2018/09/17 22:26:11 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

void	ft_wr(char c)
{
	write(1, &c, 1);
}

int		b_print_int(int integer)
{
	int		count;
	int		i;
	char	*string;

	count = 0;
	i = 0;
	string = ft_itoa_base(integer, 10);
	while (string[i])
	{
		ft_wr(string[i]);
		i++;
		count++;
	}
	return (count);
}
