/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:11:17 by medun             #+#    #+#             */
/*   Updated: 2018/09/25 18:59:46 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     b_printf(const char *fmt, ...);

int main()
{
  char s[] = "hello";
  b_printf("%d\n", b_printf("%s %s %c %d %o %u ---- %x %p\n", s, NULL, '\0', -36363, -99919, 123, 123, s));
  printf("%d\n", printf("%s %s %c %d %o %u ---- %x %p\n", s, NULL, '\0', -36363, -99919, 123, 123, s));
}