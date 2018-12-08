/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:07:40 by tcho              #+#    #+#             */
/*   Updated: 2018/11/24 02:16:54 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "fillit.h"
#include "libft.h"

void init_array(int *arr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		arr[i] = -1;
		i++;
	}
}

int *ft_intnew(size_t size)
{
	int *container;

	if (!(container = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	init_array(container, size);
	return (container);
}

char **initialize_map(char c, int size)
{
	int		i;
	char    *row;
	char    **map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * size);
	while (i < size)
	{
		row = (char *)malloc(sizeof(char) * size);
		if (!(map[i] = ft_memset(row, c, size)))
			return (NULL);
		i++;
	}
	return (map);
}

int push(int *arr, int num)
{
	int	i;

	i = 0;
	while ((arr[i] != -1) && i < 4)
		i++;
	if (i < 4)
	{
		arr[i] = num;
		return (1);
	}
	return (0);
}

int find_max(int *nums)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (i < 4)
	{
		if (nums[i] > max)
			max = nums[i];
		i++;
	}
	return (max);
}

int find_min(int *nums)
{
	int	i;
	int	min;

	i = 0;
	min = 4;
	while (i < 4)
	{
		if (nums[i] < min)
			min = nums[i];
		i++;
	}
	return (min);
}

void set_size_letter(t_pieces *list)
{
	int		letter;
	t_piece	*current;

	letter = 'A';
	current = list->head;
	while (current)
	{
		current->letter = letter++;
		current->width = find_max(current->x) - find_min(current->x) + 1;
		current->height = find_max(current->y) - find_min(current->y) + 1;
		current = current->next;
	}
}

int display_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}

void reset(t_pieces *list)
{
	int		i;
	int		y_difference;
	int		x_difference;
	t_piece	*current;

	current = list->head;
	while (current)
	{
		i = 0;
		y_difference = find_min(current->y) - 0;
		x_difference = find_min(current->x) - 0;
		while (i < 4)
		{
			current->y[i] -= y_difference;
			current->x[i] -= x_difference;
			i++;
		}
		current = current->next;
	}
}
