/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:41:27 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 17:44:20 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	alpha;
	unsigned char	*a;

	i = 0;
	a = (unsigned char*)b;
	alpha = (unsigned char)c;
	while (i < len)
	{
		a[i] = alpha;
		i++;
	}
	return (b);
}
