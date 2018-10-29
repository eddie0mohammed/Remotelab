/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:23:33 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/19 15:21:53 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include "header.h"

int		main(void)
{
	DIR *dir;
	struct dirent *dh;

	char *name = "domain.c";
	struct stat stbuf;
//	int stat(char *, struct stat *);
	dir = opendir(".");
	while ((dh=readdir(dir)) != 0)
	{
		stat(dh->d_name, &stbuf);
		b_printf("Name: %s\t\tLINK:%d\n", dh->d_name, stbuf.st_mode );
	}
	closedir(dir);
}
