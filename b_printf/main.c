/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:39:46 by medun             #+#    #+#             */
/*   Updated: 2018/09/19 20:59:35 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	b_printf(const char *restrict format, ...);

int	main(void)
{
	char			*a = NULL;
	char			b[] = "hey there,";
	char			c[] = "this is a trial version!!!...";
	char			d = 'A';
	char			e = 'b';
	int				f = -1;
	int				g = -23;
	int				h = 123;
	int				i = -100;
	unsigned int	ui = -10;
	int				xx = 100;
	int aaa = b_printf("aloha, %s %s %s %c %c %i %d %o %x %u\n%p\n",\
			a, b, c, d, e, f, g, h, i, ui, &xx);
	int bbb = printf("aloha, %s %s %s %c %c %i %d %o %x %u\n%p\n",\
			a, b, c, d, e, f, g, h, i, ui, &xx);

	printf("\n\n\n%d, %d \n", aaa, bbb);
	return (0);
}
