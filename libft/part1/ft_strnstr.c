/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:02:03 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 15:36:15 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char			*ft_strnstr(const char *haystack, \
		const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (needle[i])
	{
		while (haystack[j] && j < len)
		{
			if (haystack[j] == needle[i])
			{
				i++;
				if (needle[i] == '\0')
					return ((char*)haystack + j - ft_strlen(needle) + 1);
			}
			else
				i = 0;
			j++;
		}
		i++;
	}
	return (NULL);
}
