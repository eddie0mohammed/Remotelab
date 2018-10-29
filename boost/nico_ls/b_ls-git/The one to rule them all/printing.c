/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:57:38 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/12 15:21:38 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define TOTAL big->total += big->buffer.st_blocks
#define ADD_ND add_link(&big->dir_sub_head, &big->dir_sub_tail, big) && (TOTAL)
#define PRINT_F print_valid(3, big, big->total); free_nodes(&big->dir_sub_head)

void	print_junk(t_big *big)
{
	t_data *ptr;

	ptr = big->junk;
	if (!(big->junk))
		return ;
	while (ptr)
	{
		printf("ls: %s: No such file or directory\n", ptr->name);
		ptr = ptr->next;
	}
}

void	print_valid(int n, t_big *big, long long total)
{
	t_data *ptr;

	ptr_set(n, &ptr, big);
	if (big->flags[0] && ptr && n != 1)
		printf("total %lli\n", total);
	while (ptr)
	{
		if (big->flags[0])
		{
			printf("%s %2u %6s ", ptr->mode, ptr->links, ptr->user);
			printf("%6s ", ptr->group);
			if (ptr->mode[0] == 'c' || ptr->mode[0] == 'b')
				printf("%i, %2i %s ", ptr->major, ptr->minor, ptr->time);
			else
				printf("%6lli %s ", ptr->size, ptr->time);
		}
		if (ptr->linkpath[0] && big->flags[0])
			printf("%s -> %s\n", ptr->name, ptr->linkpath);
		else
			printf("%s\n", ptr->name);
		ptr = big->flags[2] ? ptr->last : ptr->next;
	}
}

char	*fillstat(char *path, struct dirent current, t_big *big)
{
	int		count;
	char	*temp;

	temp = NULL;
	count = ft_strlen(path) + 2 + current.d_namlen;
	if ((temp = malloc(sizeof(char) * count)) == NULL)
		return (NULL);
	temp = ft_strcpy(temp, path);
	temp[ft_strlen(path)] = '/';
	ft_strcpy((temp + (ft_strlen(path) + 1)), current.d_name);
	lstat(temp, &big->buffer);
	return (temp);
}

void	sub_dir(char *d_name, t_big *big)
{
	DIR				*dir;
	struct dirent	*current;
	char			*path;

	big->dir_sub_head = NULL;
	big->total = 0;
	if (!(dir = opendir(d_name)))
	{
		print_bad(d_name);
		return ;
	}
	while ((current = readdir(dir)))
	{
		if (big->flags[1] || ((!big->flags[1]) && !(current->d_name[0] == '.')))
		{
			path = fillstat(d_name, *current, big);
			create_node(ft_strdup(current->d_name), big, path);
			if (big->flags[1])
				ADD_ND;
			else if (!(current->d_name[0] == '.'))
				ADD_ND;
		}
	}
	PRINT_F;
	closedir(dir);
}

void	cycle_dir(t_big *big)
{
	t_data *ptr;

	if (!(big->dir_head))
		return ;
	ptr = big->flags[2] ? big->dir_tail : big->dir_head;
	while (ptr)
	{
		if (big->file_head || (!big->flags[2] ? ptr->last : ptr->next))
			printf("\n");
		if (big->junk || big->file_head || big->dir_head->next)
			printf("%s:\n", ptr->name);
		sub_dir(ptr->name, big);
		ptr = big->flags[2] ? ptr->last : ptr->next;
	}
}
