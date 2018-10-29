/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:47:20 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/13 14:47:57 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "header.h"

typedef struct		s_data
{
	char			*path;
	char			*name;
	char			*time;
	char			*mode;
	char			linkpath[200];
	char			*group;
	char			*user;
	long long		size;
	unsigned short	links;
	long			numtime;
	long			numtimenano;
	unsigned int	minor;
	unsigned int	major;
	struct s_data	*next;
	struct s_data	*last;
}					t_data;

typedef struct		s_big
{
	t_data			*junk;
	t_data			*junk_tail;
	t_data			*file_head;
	t_data			*file_tail;
	t_data			*dir_head;
	t_data			*dir_tail;
	t_data			*dir_sub_head;
	t_data			*dir_sub_tail;
	t_data			*new_node;

	struct stat		buffer;
	int				good_flags;
	char			bad_flag;
	int				flags[4];
	long long		total;
}					t_big;

#endif
