/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:13:11 by medun             #+#    #+#             */
/*   Updated: 2018/11/26 20:23:23 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char *str;
	int i;
	int base = 10;
	int n;
	int sign;

	n = (nbr < 0) ? -(long)nbr : nbr;
	sign = (nbr < 0 && base == 10) ? -1 : 1;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	n = (nbr < 0) ? -(long)nbr : nbr;
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
	return (0);
}
