/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:35:30 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/13 14:44:12 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHEADER_H
# define PHEADER_H
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <strings.h>
# include <stdlib.h>
# include "libheader.h"
# include <time.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include "structs.h"

void	input(char **argv, t_big *big);
void	init(t_big *big);
void	check_flags(char ***argv, t_big *big);
void	create_lists(char **argv, t_big *big);
void	actual_flags(char ***argv, t_big *big);

int		add_link_body(t_data **head, t_data **tail, t_big *big);
int		add_link(t_data **head, t_data **tail, t_big *big);
void	go_before(t_data **head, t_data *temp, t_big *big);
void	go_after(t_data **tail, t_data *temp, t_big *big);
void	place_node(long l, t_data **h, t_data **t, t_data *te, t_big *b);

void	create_node(char *current, t_big *big, char *test);
char	*get_mode(t_big *big);
char	*get_extra(t_big *big, char *mode);
char	*get_first(t_big *big, char *mode);
char	*time_clean(char *the_time, long numtime);

void	print_junk(t_big *big);
void	print_valid(int n, t_big *big, long long total);
void	sub_dir(char *c, t_big *b);
char	*fillstat(char *path, struct dirent current, t_big *big);
void	cycle_dir(t_big *big);

void	minor_major(t_data *node, t_big *big);
void	free_me(t_big **head);
void	ptr_set(int n, t_data **ptr, t_big *big);
void	free_nodes(t_data **head);
void    print_bad(char *d_name);

#endif
