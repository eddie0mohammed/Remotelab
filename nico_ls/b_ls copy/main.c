/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 20:22:03 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/22 15:42:43 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pheader.h"
#include "lheader.h"

void zeroflags(int *flag)
{
	flag[0] = 0; //l
	flag[1] = 0; //a
	flag[2] = 0; //t
	flag[3] = 0; //r
	flag[4] = 1; //finished flags
	flag[5] = 0; //for space in run
	flag[6] = 0; //for /n in run
}

void flags(int *flag, char *s)
{
	while (*s)
	{
		if (*s == 'l')
			flag[0] = 1;
		else if (*s == 'a')
			flag[1] = 1;
		else if (*s == 't')
			flag[2] = 1;
		else if (*s == 'r')
			flag[3] = 1;
		s++;
	}
}

void	fillstat(char *path, struct dirent current, struct stat *stats)
{
	int		count;
	char	*temp;

	count = ft_strlen(path) + 1 + current.d_namlen;
	if ((temp = malloc(sizeof(char) * count)) == NULL)
		return;
	ft_strcpy(temp, path);
	temp[ft_strlen(path)] = '/';
	ft_strcpy((temp + (ft_strlen(path) + 1)), current.d_name);
	lstat(temp, stats);
}

void walk(char *s, int *flag)
{
	DIR *dir;
	struct dirent *current;
	struct stat stats;
	t_data **nodes;

	nodes = t_datamaker();
	if (!(dir = opendir(s)))
		return;
	while ((current = readdir(dir)) != 0)
	{
		fillstat(s, *current, &stats);
//		lstat(current->d_name, &stats); 					//needs actuall dir path for files  "deleteme/test.c"
		nodes[1] = create_dir_node(current, &stats);
		if (flag[1]) //-a
		{
			//double check if new_node was returned as NULL
			link_me(&(nodes[0]), nodes[1], &(nodes[2]), flag[2]);
		}
		else if (!(((current->d_name)[0]) == '.'))
			link_me(&(nodes[0]), nodes[1], &(nodes[2]), flag[2]);
	}
	print_me(nodes[0], nodes[2], flag);
	closedir(dir);
}

int main(int argc, char **argv)
{
	int flag[7];
	struct stat stats;
	t_data **nodes_dir; //have a function that will make all the pointers and pass me an array of them?
	t_data **nodes_file;
	t_data **nodes_junk;

	nodes_dir = t_datamaker();
	nodes_file = t_datamaker();
	nodes_junk = t_datamaker();
	zeroflags(flag);
	if (argc == 1)
		walk(".", flag);
	else
	{
		while (--argc > 0)
		{
			if (**++argv == '+' && flag[4])
				flags(flag, *argv);
			else //everything after this point should be a file or directory
			{
				(flag[4]) ? flag[4] = 0 : flag[4];
				//walk(*argv, flag);			// Make list for each argv here ( if error print and skip next)
				if (lstat(*argv, &stats) == -1)
				{
					nodes_junk[1] = create_argv_node(*argv, 0);
					link_me(&(nodes_junk[0]), (nodes_junk[1]), &(nodes_junk[2]), 0);
					continue;
				}
				nodes_file[1] = create_argv_node(*argv, stats.st_mtime); //Gonna make two list for Dirs and files
				if (!S_ISDIR(stats.st_mode))
					link_me(&(nodes_file[0]), (nodes_file[1]), &(nodes_file[2]), flag[2]); //return pointer array -- all file/nonfile will be handled before. remove those files after done ... then pass linked list wtih only real dirs in it to walk
				else
					link_me(&(nodes_dir[0]), (nodes_file[1]), &(nodes_dir[2]), flag[2]);
			}
		}
		print_junk(nodes_junk[0], flag); //HAVE TO SET HEAD TO NULL FIRST
		print_files(nodes_file[0], nodes_file[2], flag, nodes_dir[0]);
		run(nodes_dir, flag);
		//file_checker(&head);			/i/free function
		if (flag[4])
			walk(".", flag);
	}
	return (0);
}

//sort struct function

//print function
