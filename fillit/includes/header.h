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
int		ft_strlen(char *str);
char	*ft_strdup(char *str);


typedef struct s_list
{
	struct s_list		*next;
	int 				ht;
	int 				wd;
	char 				*piece;
	//int				count;
	//char				letter;
}						t_list;

t_list 	*get_w_h_of_all_file(char *buf);
t_list	*calculate_width_height(char *buf, t_list *list);

t_list	*ft_create_elem(int height, int width, char *buf);
t_list	*ft_list_push_back(t_list **begin_list, int height, int width, char *buf);
int		get_size(t_list *list);

#endif
