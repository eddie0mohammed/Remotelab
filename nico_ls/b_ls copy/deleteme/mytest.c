/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 20:43:57 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/18 23:30:55 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include :x

int		main(int	argc, char **argv)
{
	if (argc == 1)
		fsize(".");		//default: current directory
	else
		while (--argc > 0)
			fsize(*++argv);
	return (0);
}
