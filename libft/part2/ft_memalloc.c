/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:22:39 by medun             #+#    #+#             */
/*   Updated: 2018/09/24 21:24:14 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*memory;

	i = 0;
	memory = malloc(sizeof(size));
	if (!(memory))
		return (NULL);
	else
	{
		while (i < size)
		{
			memory[i] = 0;
			i++;
		}
	}
	return (memory);
}
