#include "header.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

t_list	*ft_lst_new(void *content)
{
	t_list *list;

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

t_list	*ft_lst_add_back(t_list *current, t_list **lst, t_tetri *tetri)
{
	if (!current)
	{
		current = ft_lst_new(tetri);
		*lst = current;
	}
	else
	{
		current->next = ft_lst_new(tetri);
		*lst = current->next;
	}
	return (current);
}

t_list	*ft_create_list(int fd, char *buf)
{
	t_tetri	*tetri;
	t_list	*lst;
	t_list 	*current;
	int		num_pieces;
	int		condition;

	num_pieces = 0;
	current	= NULL;
	condition = 0;
	while (!condition)
	{
		if (read(fd, buf, 20) != 20)
			return (NULL);
		if ((tetri = ft_create_tetri(buf, num_pieces)))
			current = ft_lst_add_back(current, &lst, tetri);
		else
			return (NULL);
		if (!(read(fd, buf, 1)))
			condition = 1;
		num_pieces++;
	}
	return (lst);
}
