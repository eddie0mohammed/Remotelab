/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:49:29 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/26 12:33:11 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pheader.h"
#include "lheader.h"
#define NAME_TIME (flag ? (temp->numtime - new_node->numtime) \
						: ft_strcmp(new_node->name, temp->name))

t_data		*create_dir_node(struct dirent *current, struct stat *stats)
{
	t_data *node;
	
	if (!(node = malloc(sizeof(t_data))))
		return (NULL);
	node->name = current->d_name;
	node->mode = stats->st_mode;
	node->numtime = stats->st_mtime;
	node->time = time_clean(ft_strdup(ctime(&(stats->st_mtime))), node->numtime); 
	//will have to free this ft_strdup -- if I ever malloc i have to free
	node->next = NULL;
	node->last = NULL;
	return (node);
}

t_data		*create_argv_node(char *s, long numtime)
{
	t_data *node;

	if (!(node = malloc(sizeof(t_data))))
		return (NULL);
	node->name = s;
	node->numtime = numtime;
	node->next = NULL;
	node->last = NULL;
	return (node);
}

//	   		  *  HEAD  *	       *NEW*	 	*   TAIL  *	   ( -t  <-> Else lexi )
void		link_me(t_data **head, t_data *new_node, t_data **tail, int flag)
{
	t_data *temp;

	if (!(*head))
	{
		*head = new_node; //*head = *tail = malloc(sizeof(t_data));
		*tail = new_node;
		return;
	}
	else
	{
		temp = *head;
		while (temp->next && (NAME_TIME > 1))
		{
			temp = temp->next;
		}
		if (NAME_TIME < 0)
		{
			new_node->next = temp;
			new_node->last = temp->last;
			if (!(temp->last))
				*head = new_node;
			else
				temp->last->next = new_node;
			temp->last = new_node;
		}
		else
		{
			new_node->next = temp->next;
			new_node->last = temp;
			temp->next = new_node;
			if (!(new_node->next))
				*tail = new_node;
		}
	}
}



