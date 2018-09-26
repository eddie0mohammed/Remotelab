/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 22:26:52 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 14:48:17 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	i = 0;
	a = (char)c;
	while (s[i])
	{
		if (s[i] == a)
			return ((char*)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char*)s + i);
	return (NULL);
}
