/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:48:52 by medun             #+#    #+#             */
/*   Updated: 2018/09/30 16:48:54 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <dirent.h>

#include <sys/dir.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int i;

// 	i = 0;
// 	while (s1[i] != '\0' || s2[i] != '\0')
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_list_sort(t_list *begin_list)
// {
// 	t_list *current;
// 	char *temp;
// 	t_list *forward;


// 	current = begin_list;
// 	while (current != NULL)
// 	{
// 		forward = current->next;
// 		while(forward != NULL)
// 		{
// 			if (ft_strcmp(current->data, forward->data) > 0)
// 			{
// 				temp = current->data;
// 				current->data = forward->data;
// 				forward->data = temp;
// 			}
// 			forward = forward->next;
// 		}
// 		current = current->next;
// 	}
// }

t_list 	*ft_create_elem(void *data)
{
	t_list	*new;

	if(!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;
	t_list *head;

	head = *begin_list;

	temp = ft_create_elem(data);
	
	if (!head)
	{
		*begin_list = temp;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = temp;
	}
}

void	ft_argv_1(char *path)
{
	DIR 			*directory;
	//int 			fd;
	struct dirent	*rd;
	t_list 			**l_list;
	t_list			*head;

	if(!(l_list = (t_list**)malloc(sizeof(t_list))))
		return ;
	head = (t_list*)malloc(sizeof(t_list));
	head = *l_list;
	directory = opendir(path);
	if (!directory)	
	{
		// if ((fd = open(path, O_RDONLY)) != -1) // check if possible to open file
		// {
		// 	printf("%s\t", path);
		// }
		// else
		// {
		// 	printf("ls: %s: No such file or directory", path);
		// }
	}
	else
	{
		while ((rd = readdir(directory)) != NULL)
		{
			
			ft_list_push_back(l_list, (void*)(rd->d_name));	
			//printf("%s\n", rd->d_name);
		}
		//ft_list_sort(l_list);

		// while (head != NULL)
		// {
		// 	printf("%s\n", head->data);
		// 	head = head->next;
		//	}
	}
	closedir(directory);
}

int	main(int argc, char **argv)
{

	if (argc == 1)
	{
		ft_argv_1(".");
	}
	// else if (argc == 2)
	// {

	// }
	// else
	// {

	// }

	return (0);
}
