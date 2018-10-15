/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:19:37 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/19 22:43:55 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <strings.h>
#include <dirent.h>
#include "header.h"


#include <stdio.h>
#include <fcntl.h> /* flags for read and write */
#include <sys/types.h> /* typedefs */
#include <sys/stat.h> /* structure returned by stat */
#define MAX_PATH 1024

int		main(int	argc, char **argv)
{
	if (argc == 1)
		fsize(".");
	else 
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;
	if ((dfd=opendir(dir)) == NULL)
	{
		b_printf("dirwalk: can't open %s\n", dir);
		return;
	}
	while (( dp = readdir (dfd)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") == 0 || ft_strcmp(dp->d_name, "..") == 0)
			continue; /*skipselfandparent*/
		if (ft_strlen(dir)+ft_strlen(dp->d_name)+2 > sizeof(name))
			b_printf("dirwalk: name %s%ss too long\nn", dir, dp->d_name);
		else {
			b_printf("%s%s", dir, dp->d_name);
			(*fcn) (name) ;
		} 
	}
	closedir(dfd) ;
}

void fsize(char *name)
{
	struct stat stbuf;
	if (stat(name, &stbuf) ==-1)
	{
		b_printf("fsize: can't access %s\n", name);
			return;
	}
	if ((stbuf.st_mode & S_IFMT)==S_IFDIR) 
		dirwalk(name, fsize);
	b_printf("%8ld %s\n", stbuf.st_size, name);
}
