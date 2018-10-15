/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:21:28 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/18 19:26:17 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#defineNAME_MAX 14 /*longestfilenamecomponent;*/
					/* system-dependent */
typedef struct
{ 								/* portable directory entry: */
	long ino; 					/* inode number */
	char name[NAME_MAX+1]; 		/* name + '\0' terminator */
} Dirent;

typedef struct
{ int fd;
	Dirent d; 
} DIR;					/* minimal DIR: no buffering, etc. */
						/* file descriptor for directory */ 
						/* the directory entry */
DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd)
