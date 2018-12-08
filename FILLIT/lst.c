#include "header.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = content;
	}
	list->next = NULL;
	return (list);
}

t_list	*ft_lstback(t_list *current, t_list **lst, t_tet *tet)
{
	if (!current)
	{
		current = ft_lstnew(tet);
		*lst = current;
	}
	else
	{
		current->next = ft_lstnew(tet);
		current = current->next;
	}
	return (current);
}

t_list	*create_list(int fd, char *buf)
{
	t_tet	*tet;		//row, col, shape, letter
	t_list	*lst;	
	t_list	*current;
	int		count;		//count for number of pieces in file
	int		condition;	

	count = 0;
	current = NULL;
	condition = 0;
	while (!condition)
	{
		if (read(fd, buf, 20) != 20)	
			return (NULL);
		if ((tet = create_tet(buf, count)))	// create the tetrimino piece
		{
			current = ft_lstback(current, &lst, tet); // add tetrimino to the list
		}
		else
			return (NULL);
		if (!read(fd, buf, 1)) //read the new line after block
			condition = 1;
		count++;	// increase tetrimino count by 1
	}
	return (lst);
}
