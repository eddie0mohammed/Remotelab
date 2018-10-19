#include "ft_list.h"
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void	ft_argc_1_2(char *path)
{
	DIR 	*directory;
	struct dirent *rd;
	int fd;
	t_list *head;

	head = NULL;
	if (!(directory = opendir(path))) // fail to open directory=> check if its a file
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
	else	// successfully opened directory // => read contents of directory
	{
		while ((rd = readdir(directory)) != NULL)
		{
			if (rd->d_name[0] == '.')
				continue;
			
			ft_list_push_back(&head, (void*)ft_strdup(rd->d_name));
		}
		closedir(directory);
	}

	// SORT
	ft_list_sort(head);

	//OUTPUT
	while (head != NULL)
	{
		// if (head->data == '.')
		// 	continue;
		printf("%s\n", head->name);
		head = head->next;
	} 
}
// /////////////above good for now
void	ft_argc_more2(int argc, char **argv)
{
	int i;
	DIR *directory;
	struct dirent *rd;
	int fd;
	t_list	*head;

	head = NULL;
	i = 1;
	while (i < argc) // if file/directory name doesnt exist.
	{
		if ((!(directory = opendir(argv[i]))) && (fd = open(argv[i], O_RDWR)) == -1)
			ft_list_push_back(&head, (void*)ft_strdup(argv[i])); // assign non-existing data to linkedlist, then sort and print
			//printf("ls: %s: No such file or directory\n", argv[i]);
		i++;
	}
	///////
	// SORT
	ft_list_sort(head);

	//OUTPUT
	// if (head == NULL)
	// 	return ;
	while (head != NULL)
	{
		// if (head->data == '.')
		// 	continue;
		printf("ls: %s: No such file or directory\n", head->data);
		//printf("%s\n", head->data);
		head = head->next;
	}
	// clear list for next step
	ft_list_clear(&head);

// 	//===========================================================================
// 	//////????????????NEXT
// 	/////// CHECK for multiple files 
	i = 1;
	while (i < argc) // loop check if not directory=> check for files
	{
		//directory = opendir(argv[i]);
		if ((!(directory = opendir(argv[i]))) && (fd = open(argv[i], O_RDWR)) != -1)
		{
			// if (rd->d_name[0] == '.')
			// 	continue;
			
			ft_list_push_back(&head, (void*)ft_strdup(argv[i]));
			
			//printf("%s\t", argv[i]);
			close(fd);
		}
		i++;			
	}

	ft_list_sort(head);
	
	// if (head == NULL)
	// 	return ;
	while (head != NULL)
	{
		// if (head->data == '.')
		// 	continue;
		printf("%s\n", head->data);
		//printf("%s\n", head->data);
		head = head->next;
	}
	// clear list for next step
	ft_list_clear(&head);

// 	//printf("HEYYYYYYYYYYYYYYYYYYYYYY" );
// 	//=============================================================


// 	// //////sort argv
// 	// i = 1;
// 	// while (i < argc)
// 	// {


// 	// }

// 		/// Check for directories
// 	t_list *inside_directory;

// 	inside_directory = NULL;



// 	i = 1;
// 	while (i < argc)
// 	{
// 		//directory = opendir(argv[i]);
// 		if ((directory = opendir(argv[i])) != NULL)
// 		{
// 			printf("\n");
// 			ft_list_push_back(&head, (void*)ft_strdup(argv[i]));
// 			//printf("%s:\n", argv[i]);
// 			while ((rd = readdir(directory)) != NULL)
// 			{
// 				if (rd->d_name[0] == '.')
// 					continue;
			
// 				ft_list_push_back(&inside_directory, (void*)ft_strdup(rd->d_name));
// 				//ft_list_push_back(&head, (void*)ft_strdup(argv[i]));
// 			}
// 			// printf("\n\n%s:\n", argv[i]);
// 			// ft_argc_1_2(argv[i]);
// 			closedir(directory);


// 			// // SORT
// 			// ft_list_sort(head);

// 			// // //OUTPUT
// 			// printf("%s:\n", argv[i]);
// 			// while (head != NULL)
// 			// {
// 			// 	// if (head->data == '.')
// 			// 	// 	continue;
// 			// 	printf("%s\n", head->data);
// 			// 	//printf("%s\n", head->data);
// 			// 	head = head->next;
// 			// }
// 		}
		
// 		i++;
// 	}

// 	// SORT
// 	ft_list_sort(head);
// 	ft_list_sort(inside_directory);

// 	// //OUTPUT
// 	// if (head == NULL)
// 	// 	return ;

// 	while (head != NULL)
// 	{
// 		// if (head->data == '.')
// 		// 	continue;
// 		printf("%s:\n", head->data);

// 		while (inside_directory != NULL)
// 		{
// 			printf("%s\n",inside_directory->data);
// 			inside_directory = inside_directory->next;
// 		}


// 		printf("\n");
// 		//printf("%s\n", head->data);
// 		head = head->next;
// 	} 

// }



int	main(int argc, char **argv)
{
	// DIR 	*directory;
	// struct dirent *rd;
	// int i;
	// int fd;
	// t_list *head;

	// i = 1;
	// head = NULL;

	// while (argv[i])
	// {
	// 	directory = opendir(argv[i]);
	// 	if (directory == NULL) // fail to open directory-> not a directory // => check if its a file
	// 	{
	// 		fd = open(argv[i], O_RDWR);
	// 		if (fd == -1)
	// 		{
	// 			printf("ls: %s: No such file or directory\n", argv[i]);
	// 			printf("\n");
	// 		}
	// 		else
	// 		{
	// 			printf("%s\n", argv[i]);
	// 			printf("\n");
	// 			close(fd);
	// 		}
	// 	}
	// 	else	// successfully opened directory // => read contents of directory
	// 	{
	// 		while ((rd = readdir(directory)) != NULL)
	// 		{
	// 			if (rd->d_name[0] == '.')
	// 				continue;
				
	// 			ft_list_push_back(&head, (void*)ft_strdup(rd->d_name));
	// 		}
	// 		closedir(directory);
	// 	}
	// 	i++;
	// }
	if (argc < 2)
	{
		ft_argc_1_2(".");
	}
	// else if (argc == 2)
	// {
	// 	ft_argc_1_2(argv[1]);
	// }
	// else if (argc > 2)
	// {
	// 	ft_argc_more2(argc, argv);
	// }

	//ft_list_sort(head);
	// ft_printandfree(&head);
	// while (head != NULL)
	// {
	// 	// if (head->data == '.')
	// 	// 	continue;
	// 	printf("%s\n", head->data);
	// 	head = head->next;
	// }

	return (0);
}