/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:31:13 by medun             #+#    #+#             */
/*   Updated: 2018/11/24 18:31:59 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		validate_piece(char *buf, int ret);
int		validate_blocks(char *buf, int ret);
char	*validate_file(int fd);

typedef struct s_tetrimino
{
	struct s_tetrimino	*next;
	int 				height;
	int 				width;
	//char 				array[4][4];
	//int				count;
	//char				letter;
}						t_tetrimino;

#endif
