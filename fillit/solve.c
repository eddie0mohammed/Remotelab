/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 03:40:49 by tcho              #+#    #+#             */
/*   Updated: 2018/11/24 03:22:52 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"



#include <stdio.h>



int	get_init_size(int piece_count)
{
	int i;
	int total_spots;

	i = 2;
	total_spots = piece_count * 4;
	while ((i * i) < total_spots)
		i++;
	return (i);
}

void remove_piece(char **map, t_piece *current, int i, int j)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (map[i + current->y[index]][j + current->x[index]] == current->letter)
			map[i + current->y[index]][j + current->x[index]] = '.';
		index++;
	}
}

int check_fit(char **map, t_piece *current, int size, int i, int j)
{
	int index;

	index = 0;

	/*
	printf("----------------------\n");
	printf("size: %d\n", size);
	printf("j = %d		current->width = %d\n", j, current->width);
	printf("i = %d		current->height = %d\n", i, current->height);
	printf("map[][] = %c\n", map[i + current->y[index]][j + current->x[index]]);
	printf("----------------------\n");
	*/
	
	if (((j + current->width) <= size) && ((i + current->height) <= size) && (map[i + current->y[index]][j + current->x[index]] == '.')) 
	{
		while (index < 4)
		{
			// Don't need to check `i + current->[index] < size` because of the previous if statement.
			// if ((i + current->y[index] < size) && (j + current->x[index] < size) && (map[i + current->y[index]][j + current->x[index]] != '.'))
			if (map[i + current->y[index]][j + current->x[index]] != '.')
				return (0);
			map[i + current->y[index]][j + current->x[index]] = current->letter;
			index++;
		}
		printf("--------------\n");
		display_map(map, size);
		printf("--------------\n");
		return (1);
	}
	return (2);
}

int fill_board(char **map, t_piece *current, int size)
{
	int	i;
	int	j;
	int result;
	
	i = 0;
	if (current == NULL)
		return (1);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			result = check_fit(map, current, size, i, j);
			if (result == 0)
				remove_piece(map, current, i, j);
			else if (result == 1)
			{
				if (fill_board(map, current->next, size))
					return (1);
				remove_piece(map, current, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int solve(t_pieces *list)
{
	int		size;
	char	**map;

	size = get_init_size(list->size);

	/*
	map = initialize_map('.', size);
	fill_board(map, list->head, size);
	return (display_map(map, size));
	*/

	while ((map = initialize_map('.', size)) && !fill_board(map, list->head, size))
		size++;
	return (display_map(map, size));
}
