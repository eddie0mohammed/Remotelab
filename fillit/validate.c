/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:01:14 by tcho              #+#    #+#             */
/*   Updated: 2018/11/24 02:13:50 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int valid_char(char *buffer, int i, t_piece *node)
{ 
	if (((i + 1) / 5) > 0 && ((i + 1) % 5) == 0)
	{
		if (buffer[i] != '\n')
			return (0);
	}
	else if (buffer[i] == '#')
	{
		node->hash_count++;
		if (!push(node->x, ((i + 1) % 5) - 1) || !push(node->y, (i + 1) / 5))
			return (0);
	}
	else if (buffer[i] == '.')
		node->dot_count++;
	else
		return (0);
	return (1);
}

int verify_newline(int fd)
{
	char	buffer[2];

	if (read(fd, buffer, 1))
	{
		buffer[1] = '\0';
		if (buffer[0] != '\n')
			return (0);
	}
	return (1);
}

int validate_file(int fd, t_pieces *list)
{
    int     i;
    int     bytes;
    char    buffer[21];
	t_piece	*node;

    while ((bytes = read(fd, buffer, 20)))
    {
        buffer[bytes] = '\0';
		i = 0;
		if (!(node = init_node()))
			return (0);
		while (buffer[i])
		{
			if (!valid_char(buffer, i, node))
				return (0);
			i++;
		}
		add_node(&list, node);
		if (!verify_newline(fd) || !check_count(node->hash_count, node->dot_count) || !validate_piece(node))
			return (0);
	}
	return (1);
}

int check_count(int hash_count, int dot_count)
{
    if (hash_count != 4 || dot_count != 12)
        return (0);
    return (1);
}

int	verify_hash(int y, int x, char **map)
{
	if (x < 0 || x > 3 || y < 0 || y > 3 || map[y][x] != '#')
		return (0);
	map[y][x] = '.';
	return (1 + verify_hash(y + 1, x, map) + verify_hash(y - 1, x, map) + verify_hash(y, x + 1, map) + verify_hash(y, x - 1, map));
}

int validate_piece(t_piece *node)
{
	int		i;
	char	**map;
	
	i = 0;
	// Need to clear at the end of the function or else memory leaks.
	map = initialize_map('.', 4);
	while (i < 4)
	{
		map[(node->y)[i]][(node->x)[i]] = '#';
		i++;
	}
	if (verify_hash((node->y)[0], (node->x)[0], map) != 4)
		return (0);
	return (1);
}

int validate_size(t_pieces *list)
{
    if (list->size < 1 || list->size > 26)
        return (0);
    return(1);
}
