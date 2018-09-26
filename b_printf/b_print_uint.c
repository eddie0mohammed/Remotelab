/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:40:35 by medun             #+#    #+#             */
/*   Updated: 2018/09/17 22:39:32 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_aa(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr((nbr / 10));
	}
	ft_aa((nbr % 10) + '0');
}

int		b_print_uint(unsigned int uint)
{
	int				count;
	int				i;
	unsigned int	temp;

	i = 0;
	count = 0;
	temp = uint;
	while (temp != 0)
	{
		count++;
		temp = temp / 10;
	}
	ft_putnbr(uint);
	return (count);
}
