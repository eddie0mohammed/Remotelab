/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:50:28 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/13 14:50:48 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHEADER_H
# define LIBHEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
