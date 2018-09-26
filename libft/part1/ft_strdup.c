/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:10:18 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 14:51:04 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s1)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!(new_str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
