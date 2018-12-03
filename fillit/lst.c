#include "includes/header.h"
#include <stdlib.h>

t_list	*ft_create_elem(int height, int width, char *buf)
{
	t_list	*new_node;

	if (!(new_node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_node->ht = height;
	new_node->wd = width;
	new_node->piece = ft_strdup(buf);
	new_node->next = NULL;

	return (new_node);
}

t_list	*ft_list_push_back(t_list **begin_list, int height, int width, char *buf)
{
	t_list	*temp;
	t_list	*head;
	t_list	*current;

	head = *begin_list;
	temp = ft_create_elem(height, width, buf);
	if (!head)
		head = temp;
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = temp;
	}
	return (head);
}

int		get_size(t_list *list)
{
	int count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}