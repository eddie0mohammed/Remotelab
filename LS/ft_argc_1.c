#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include "structs.h"
#include "ft_header.h"

void	ft_argc_1(char *path)
{
	DIR 				*directory;
	struct dirent		*rd;
	int					fd;
	t_data				*head;

	head = NULL;
	if (!(directory = opendir(path)))	//not a directory
	{
		if ((fd = open(path, O_RDWR)) == -1)
		{
			printf("ls: %s: No such file or directory\n", path);
		}
		else
		{
			printf("%s\n", path);
			close(fd);
		}

	}
	else	//successfully open directory
	{
		while ((rd = readdir(directory)) != NULL)
		{
			if (rd->d_name[0] == '.')
				continue;
			//create a new linked list and put "name" only in there
			ft_list_push_back(&head, (void*)strdup(rd->d_name));	
		}
		closedir(directory);
	}

	//SORT
	ft_list_sort(head);

	//OUTPUT
	while (head != NULL)
	{
		printf("%s\n", head->name);
		head = head->next;
	}
}