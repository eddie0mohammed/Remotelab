/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:48:06 by medun             #+#    #+#             */
/*   Updated: 2018/09/23 19:46:05 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int	ft_tolower(int c);
int ft_toupper(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isalpha(int c);
int ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
	char a = 'K';
	char b = 'l';
	char atoii[] = " \n \t \v \f -123abs56";
	char len[] = "hello";
	char len1[] = "abcde";
	
//	printf("%c\n", ft_tolower(a));
//	printf("%c\n", ft_toupper(b));
//	printf("%d\n", ft_isprint(127));
//	printf("%d\n", isprint(127));
//	printf("%d\n", ft_isascii(100));
//	printf("%d\n", isascii(100));

	//printf("%d\n", isalnum(100));
	//printf("%d\n", ft_isalnum(100));
	//printf("%d\n", ft_isdigit(5));
	//printf("%d\n", ft_isdigit(5));
	//printf("%d\n", ft_isalpha(100));
	//printf("%d\n", isalpha(100));
	//printf("%d\n", ft_atoi(atoii));
	//printf("%d\n", atoi(atoii));
	//
	//printf("%lu\n",ft_strlen(len));
	//printf("%lu\n",strlen(len));

	//printf("%s\n", ft_strdup(len));
	//printf("%s\n", strdup(len));
	//printf("%d\n", ft_strcmp(len, len1));
	//printf("%d\n", strcmp(len, len1));
printf("%d\n", ft_strncmp(len, len1, 8));
printf("%d\n", strncmp(len, len1, 8));

	return (0);	
}
