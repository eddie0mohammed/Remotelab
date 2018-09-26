/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:34:57 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 15:34:01 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (needle[i])
	{
		while (haystack[j])
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
