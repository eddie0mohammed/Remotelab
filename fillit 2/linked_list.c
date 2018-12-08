/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:01:50 by tcho              #+#    #+#             */
/*   Updated: 2018/11/23 18:06:19 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

t_pieces *init_list(void)
{
    t_pieces *list;

    if (!(list = (t_pieces *)malloc(sizeof(t_pieces))))
        return (NULL);
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return (list);
}

t_piece *init_node(void)
{
    t_piece *node;

    if (!(node = (t_piece *)malloc(sizeof(t_piece))))
        return (NULL);
    node->letter = 0;
	node->hash_count = 0;
	node->dot_count = 0;
	node->width = 0;
	node->height = 0;
	node->x = ft_intnew(4);
	node->y = ft_intnew(4);
    node->next = NULL;
    return (node);
}

void add_node(t_pieces **list, t_piece *node)
{
    if (!(*list)->head)
    {
        (*list)->head = node;
        (*list)->tail = node;
    }
    else
    {
        (*list)->tail->next = node;
        (*list)->tail = node;
    }
    (*list)->size++;
}

void remove_node(t_pieces **list, int index)
{
    t_piece *parent;
    t_piece *current;
    int i;

    if (!(*list)->head)
        return ;
    parent = NULL;
    current = (*list)->head;
    i = 0;
    while (current && i < index)
    {
        parent = current;
        current = current->next;
        i++;
    }
    if (i == 0)
        (*list)->head = current->next;
    else
        parent->next = current->next;
    free_node(current);
}

void free_node(t_piece *current)
{
    free(current->x);
	free(current->y);
	free(current->next);
    free(current);
}

void free_all(t_pieces **list)
{
    t_piece *current;
    t_piece *temp;

    if (!(*list))
        return ;
    current = (*list)->head;
    while (current)
    {
        temp = current;
        current = current->next;
        free_node(temp);
    }
}


// PRINTF
#include <stdio.h>
// PRINTF



void display(t_pieces *list)
{
	int i;
	t_piece *current;

	current = list->head;
	while (current)
	{
		printf("%d %d\n", current->hash_count, current->dot_count);
		i = 0;
		while (i < 4)
		{
			printf("%d %d\n", current->x[i], current->y[i]);
			i++;
		}
		current = current->next;
	}
}

void display_visual(t_pieces *list)
{
	int i;
	t_piece *current;
	char **map;

	current = list->head;
	while (current)
	{
		i = 0;
		map = initialize_map('.', 4);
		while (i < 4)
		{
			map[(current->y)[i]][(current->x)[i]] = '#';
			i++;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ft_putchar(map[i][j]);
			}
			ft_putchar('\n');
		}
		ft_putchar('\n');
		current = current->next;
	}
}
