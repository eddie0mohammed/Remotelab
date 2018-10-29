/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:18:29 by medun             #+#    #+#             */
/*   Updated: 2018/09/19 21:00:07 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

void				ft_aaa(char c)
{
	write(1, &c, 1);
}

int					condition(va_list lst, char c, int count)
{
	if (c == 's')
		count = count + b_print_string(va_arg(lst, char*));
	else if (c == 'c')
		count = count + b_print_char(va_arg(lst, int));
	else if (c == '%')
	{
		count++;
		ft_aaa(c);
	}
	else if (c == 'd' || c == 'i')
		count = count + b_print_int(va_arg(lst, int));
	else if (c == 'o')
		count = count + b_print_octal(va_arg(lst, int));
	else if (c == 'x')
		count = count + b_print_hex(va_arg(lst, unsigned int));
	else if (c == 'u')
		count = count + b_print_uint(va_arg(lst, unsigned int));
	else if (c == 'p')
		count = count + b_print_add(va_arg(lst, unsigned long));
	return (count);
}

int					b_printf(const char *restrict format, ...)
{
	va_list			lst;
	int				i;
	int				count;
	char			c;

	i = -1;
	count = 0;
	va_start(lst, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			c = format[i];
			count = condition(lst, c, count);
		}
		else
		{
			ft_aaa(format[i]);
			count++;
		}
	}
	va_end(lst);
	return (count);
}
