/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:36:47 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/19 22:43:17 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

int		b_printf(const char *c, ...);
void    fsize(char *);
int		ft_strlen(char *s);
int		ft_strcmp(const char *s1, const char *s2);
void    dirwalk(char *dir, void (*fcn)(char *));
#endif
