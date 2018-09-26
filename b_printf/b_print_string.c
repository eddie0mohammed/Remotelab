/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 18:28:52 by medun             #+#    #+#             */
/*   Updated: 2018/09/19 21:00:45 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_a(char c)
{
	write(1, &c, 1);
}

int		b_print_null(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		ft_a(str[i]);
		i++;
		count++;
	}
	return (count);
}

int		b_print_string(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str == NULL)
	{
		count += b_print_null("(null)");
	}
	else
	{
		while (str[i])
		{
			ft_a(str[i]);
			i++;
			count++;
		}
	}
	return (count);
}
