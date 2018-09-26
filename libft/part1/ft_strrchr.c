/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 22:34:12 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 14:56:59 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strrchr(const char *s, int c)
{
	int		i;
	char	alpha;

	i = 0;
	alpha = (char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == alpha)
			return ((char*)s + i);
		i--;
	}
	return (NULL);
}
