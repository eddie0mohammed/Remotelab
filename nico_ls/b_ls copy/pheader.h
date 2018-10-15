/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:15:16 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/22 15:42:17 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHEADER_H
# define PHEADER_H
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h> //delete me later

typedef struct	s_data
{
	char			*name;
	char			*time;
	int				mode;
	long			numtime;
	struct s_data	*next;
	struct s_data	*last;
}					t_data;


t_data				**t_datamaker();
t_data				*create_argv_node(char *s, long numtime);
t_data				*create_dir_node(struct dirent *c, struct stat *s);
char				*time_clean(char *time, long numtime);
int     			b_printf(const char *c, ...);
void 				reg(t_data *ptr, int *flag);
void 				longformat(t_data *ptr, int *flag);
void				fillstat(char *path, struct dirent current, struct stat *stats);
void 				walk(char *s, int *flag);
void				fsize(char *name);
void				link_me(t_data **head, t_data *new_node, t_data **tail, int s);
void				print_me(t_data *,t_data *, int *);
void				print_files(t_data *head, t_data *tail, int *flag, t_data *other_head);
void    			print_junk(t_data *head, int *flag);
void				run(t_data **node_dir, int *flag);
void				file_checker(t_data **head);
#endif
