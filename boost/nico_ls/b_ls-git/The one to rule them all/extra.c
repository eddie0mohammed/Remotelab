/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:43:20 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/13 18:49:04 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "errno.h"

void	ptr_set(int n, t_data **ptr, t_big *big)
{
	if (n == 1)
		*ptr = big->flags[2] ? big->file_tail : big->file_head;
	else if (n == 2)
		*ptr = big->flags[2] ? big->dir_tail : big->dir_head;
	else
		*ptr = big->flags[2] ? big->dir_sub_tail : big->dir_sub_head;
}

void	init(t_big *big)
{
	big->junk = NULL;
	big->junk_tail = NULL;
	big->file_head = NULL;
	big->file_tail = NULL;
	big->dir_head = NULL;
	big->dir_tail = NULL;
	big->dir_sub_head = NULL;
	big->dir_sub_tail = NULL;
	big->good_flags = 0;
	ft_memset(big->flags, 0, sizeof(big->flags));
}

void	minor_major(t_data *node, t_big *big)
{
	if (node->mode[0] == 'c' || node->mode[0] == 'b')
	{
		node->major = major(big->buffer.st_rdev);
		node->minor = minor(big->buffer.st_rdev);
	}
}

void	print_bad(char *d_name)
{
	if ((strrchr(d_name, '/')))
		printf("ls: %s: %s\n", (strrchr(d_name, '/') + 1), strerror(errno));
	else
		printf("ls: %s: %s\n", (d_name), strerror(errno));
	return ;
}

void	free_nodes(t_data **head)
{
	t_data *ptr;

	ptr = *head;
	if (ptr)
	{
		free(ptr->mode);
		free(ptr->path);
		free(ptr->time);
		free(ptr->user);
		free(ptr->group);
		free(ptr->name);
		if (ptr->next)
			free_nodes(&ptr->next);
		free(ptr);
	}
}
