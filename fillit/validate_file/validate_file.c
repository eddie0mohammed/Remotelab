/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:35:13 by medun             #+#    #+#             */
/*   Updated: 2018/11/25 18:35:15 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int	helper1(int i, int j, char *buf, int ret)
{
	while (i <= j)
	{
		if (buf[ret - 1] == '\n')
			return (-1);
		if (buf[i - 1] == '\0')
		{
			if (validate_blocks(buf, ret) == -1)
				return (-1);
			return (1);
		}
		if (buf[i - 1] != '\n')
			return (-1);
		if (i == j && buf[i] != '\n' && buf[i] != '\0')
			return (-1);
		if (i == j && buf[i] == '\n')
		{
			i += 1;
			j += 21;
		}
		i += 5;
	}
	return (1);
}

char	*validate_file(int fd)
{
	char	*buf;
	int		ret;
	int		i;
	int		j;

	if (!(buf = (char*)malloc(sizeof(char) * (547))))
		return (NULL);
	if ((ret = read(fd, buf, 546)) != -1)
		buf[ret] = '\0';
	j = 20;
	i = 5;
	if (helper1(i, j, buf, ret) == -1)
		return (NULL);
	return (buf);
}
