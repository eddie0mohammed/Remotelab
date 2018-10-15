/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:29:07 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/18 21:30:12 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <dirent.h>
void main(int argc,char *argv[])
{
	DIR *dir;
	struct dirent *dent;
	dir = opendir(argv[1]);   

	if (dir!=NULL)
	{
		while ((dent=readdir(dir))!=NULL)
		{
			if ((strcmp(dent->d_name,".") == 0 || strcmp(dent->d_name,"..") == 0 || (*dent->d_name) == '.' ))
			{
			}
			else
			{
				printf(dent->d_name);
				printf("\n");
			}
		}
	}
	close(dir);
}
int	test(void)
{
	DIR *dir;
	struct dirent *sd;

	dir = opendir(".");

	if (dir == NULL)
	{
		printf("bad directory\n");
		exit(1);
	}
	while ((sd=readdir(dir)) != NULL)
	{
		printf(">> %s\n", sd->d_name);
	}

	closedir(dir);
	return (0);
}
