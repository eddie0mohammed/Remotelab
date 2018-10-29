 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:57:06 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/12 15:18:09 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define BAD_FLAG "ls: illegal option -- %c\nusage: ls [-lart] [file ...]\n"

int		main(int argc, char **argv)
{
	t_big *big;

	argc = 0;
	if (!(big = malloc(sizeof(t_big))))
		return (0);
	init(big);
	input(argv, big);
	if (!big->good_flags)
	{
		print_junk(big);
		print_valid(1, big, 0);
		cycle_dir(big);
	}
	if (big->good_flags == 1)
		printf(BAD_FLAG, '-');
	else if (big->good_flags == 2)
		printf(BAD_FLAG, big->bad_flag);
}

void	input(char **argv, t_big *big)
{
	check_flags(&argv, big);
	if (!big->good_flags)
		(!(*argv)) ? sub_dir(".", big) : create_lists(argv, big);
	return ;
}

void	actual_flags(char ***argv, t_big *big)
{
	while (*++(**argv))
	{
		if (***argv == 'l')
			big->flags[0] = 1;
		else if (***argv == 'a')
			big->flags[1] = 1;
		else if (***argv == 'r')
			big->flags[2] = 1;
		else if (***argv == 't')
			big->flags[3] = 1;
		else
		{
			big->good_flags = 2;
			big->bad_flag = ***argv;
			return ;
		}
	}
}

void	check_flags(char ***argv, t_big *big)
{
	while (*(++*argv) && (***argv == '-'))
	{
		if (*(**argv + 1) == '-')
		{
			if (*(**argv + 2) == '\0')
				++*argv;
			else
				big->good_flags = 1;
			return ;
		}
		if (*(**argv + 1) == '\0')
			return ;
		actual_flags(argv, big);
	}
}

void	create_lists(char **argv, t_big *big)
{
	while (*argv)
	{
		create_node(*argv, big, *argv);
		if (lstat(*argv, &big->buffer) == -1)
			add_link(&big->junk, &big->junk_tail, big);
		else if (!S_ISDIR(big->buffer.st_mode))
		{
			if (((S_ISLNK(big->buffer.st_mode) && !(big->flags[0]))))
				add_link(&big->dir_head, &big->dir_tail, big);
			else
				add_link(&big->file_head, &big->file_tail, big);
		}
		else
			add_link(&big->dir_head, &big->dir_tail, big);
		argv++;
	}
}
