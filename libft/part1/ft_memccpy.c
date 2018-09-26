/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:19:38 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 18:34:50 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *restrict dst, \
		const void *restrict src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = (unsigned char)c;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == ch)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
