/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:52:40 by medun             #+#    #+#             */
/*   Updated: 2018/09/17 22:24:52 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_writ(char c)
{
	write(1, &c, 1);
}

char	*ft_itoa_b_add(unsigned long value, unsigned long base)
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

int		b_print_add(unsigned long add)
{
	int		count;
	int		i;
	char	*str;

	i = 0;
	count = 0;
	str = ft_itoa_b_add(add, 16);
	write(1, "0x", 2);
	count += 2;
	while (str[i])
	{
		ft_writ(str[i]);
		i++;
		count++;
	}
	return (count);
}
