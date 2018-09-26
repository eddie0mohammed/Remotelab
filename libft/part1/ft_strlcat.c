/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 21:43:12 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 14:56:19 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t			ft_strlcat(char *restrict dst, \
		const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	while (dst[i])
		i++;
	dst_len = i;
	if (dstsize < dst_len + 1)
		return (src_len + dstsize);
	while (src[j] && (j < (dstsize - dst_len - 1)))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (src_len + dst_len);
}
