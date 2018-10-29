/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:57:21 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/11 15:14:24 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_node(char *current, t_big *big, char *test)
{
	t_data *node;

	if (!(node = malloc(sizeof(t_data))))
		return ;
	ft_memset(node->linkpath, '\0', 200);
	if (!lstat(test, &big->buffer))
	{
		node->path = test;
		node->numtime = big->buffer.st_mtimespec.tv_sec;
		node->numtimenano = big->buffer.st_mtimespec.tv_nsec;
		node->mode = get_mode(big);
		node->time = time_clean(ctime(&(big->buffer.st_mtime)), node->numtime);
		node->links = big->buffer.st_nlink;
		node->user = ft_strdup(getpwuid(big->buffer.st_uid)->pw_name);
		node->group = ft_strdup(getgrgid(big->buffer.st_gid)->gr_name);
		node->size = big->buffer.st_size;
		readlink(node->path, node->linkpath, 199);
		minor_major(node, big);
	}
	node->name = current;
	node->next = NULL;
	node->last = NULL;
	big->new_node = node;
}

char	*get_mode(t_big *big)
{
	char	*mode;
	int		n;

	n = 0;
	if (!(mode = malloc(sizeof(char) * 11)))
		return (NULL);
	mode[n++] = S_ISDIR(big->buffer.st_mode) ? 'd' : '-';
	mode[n++] = (big->buffer.st_mode & S_IRUSR) ? 'r' : '-';
	mode[n++] = (big->buffer.st_mode & S_IWUSR) ? 'w' : '-';
	mode[n++] = (big->buffer.st_mode & S_IXUSR) ? 'x' : '-';
	mode[n++] = (big->buffer.st_mode & S_IRGRP) ? 'r' : '-';
	mode[n++] = (big->buffer.st_mode & S_IWGRP) ? 'w' : '-';
	mode[n++] = (big->buffer.st_mode & S_IXGRP) ? 'x' : '-';
	mode[n++] = (big->buffer.st_mode & S_IROTH) ? 'r' : '-';
	mode[n++] = (big->buffer.st_mode & S_IWOTH) ? 'w' : '-';
	mode[n++] = (big->buffer.st_mode & S_IXOTH) ? 'x' : '-';
	mode[n] = '\0';
	mode = get_extra(big, mode);
	return (mode);
}

char	*get_extra(t_big *big, char *mode)
{
	int n;

	if (!mode)
		return (NULL);
	n = 0;
	if (big->buffer.st_mode & S_ISUID)
		mode[3] = (mode[3] == '-') ? 'S' : 's';
	if (big->buffer.st_mode & S_ISGID)
		mode[6] = (mode[6] == '-') ? 'S' : 's';
	if (big->buffer.st_mode & 0001000)
		mode[9] = (mode[9] == '-') ? 'T' : 't';
	mode = get_first(big, mode);
	return (mode);
}

char	*get_first(t_big *big, char *mode)
{
	if (S_ISBLK(big->buffer.st_mode))
		mode[0] = 'b';
	else if (S_ISCHR(big->buffer.st_mode))
		mode[0] = 'c';
	else if (S_ISDIR(big->buffer.st_mode))
		mode[0] = 'd';
	else if (S_ISLNK(big->buffer.st_mode))
		mode[0] = 'l';
	else if (S_ISSOCK(big->buffer.st_mode))
		mode[0] = 's';
	else if (S_ISFIFO(big->buffer.st_mode))
		mode[0] = 'P';
	else
		mode[0] = '-';
	return (mode);
}

char	*time_clean(char *the_time, long numtime)
{
	char *temp;

	if ((temp = malloc(sizeof(char) * 13)) == NULL)
		return (NULL);
	temp[12] = '\0';
	if ((time(NULL) - numtime) > 15780000)
	{
		ft_strncpy(temp, (the_time + 4), 7);
		ft_strncpy((temp + 7), (the_time + 19), 5);
	}
	else
		temp = ft_strncpy(temp, (the_time + 4), 12);
	return (temp);
}
