/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:17:17 by medun             #+#    #+#             */
/*   Updated: 2018/09/17 22:26:29 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_w(char c)
{
	write(1, &c, 1);
}

char	*ft_itoa_add(unsigned long value, unsigned long base)
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

int		b_print_octal(unsigned int octal)
{
	int		count;
	int		i;
	char	*str;

	count = 0;
	i = 0;
	str = ft_itoa_add(octal, 8);
	while (str[i])
	{
		ft_w(str[i]);
		i++;
		count++;
	}
	return (count);
}
