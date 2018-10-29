/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:10:13 by medun             #+#    #+#             */
/*   Updated: 2018/09/17 22:30:15 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_xx(char c)
{
	write(1, &c, 1);
}

char	*ft_itoa_badd(unsigned long value, unsigned long base)
{
	char			*s;
	unsigned long	n;
	unsigned long	i;

	n = value;
	i = 0;
	while ((n /= base) >= 1)
		i++;
	i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

int		b_print_hex(unsigned int hex)
{
	int		count;
	int		i;
	char	*str;

	i = 0;
	count = 0;
	str = ft_itoa_badd(hex, 16);
	while (str[i])
	{
		ft_xx(str[i]);
		i++;
		count++;
	}
	return (count);
}
