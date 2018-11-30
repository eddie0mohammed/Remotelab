/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:38:52 by medun             #+#    #+#             */
/*   Updated: 2018/11/25 18:38:53 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	helper2(int i, int ret, char *buf, int *dot_hash)
{
	while (i <= ret)
	{
		if (i == ret && dot_hash[0] == 12 && dot_hash[1] == 4)
			break ;
		else if (i == ret && (dot_hash[0] != 12 || dot_hash[1] != 4))
			return (-1);
		if (buf[i] == '.')
			dot_hash[0]++;
		else if (buf[i] == '#')
			dot_hash[1]++;
		else if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			if (dot_hash[0] == 12 && dot_hash[1] == 4)
				i++;
			else
				return (-1);
			dot_hash[0] = 0;
			dot_hash[1] = 0;
		}
		i++;
	}
	return (1);
}

int	validate_blocks(char *buf, int ret)
{
	int dot_hash[2];
	int i;

	dot_hash[0] = 0;
	dot_hash[1] = 0;
	i = 0;
	if (helper2(i, ret, buf, dot_hash) == -1)
		return (-1);
	if (validate_piece(buf, ret) == -1)
		return (-1);
	return (1);
}
