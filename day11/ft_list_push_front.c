#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*new_node;

	if (!(new_node = (t_list*)malloc(sizeof(t_list))))
	return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);	
}

void 	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list 	*temp;
	t_list 	*head;

	head = *begin_list;
	temp = ft_create_elem(data);
	if (!(*begin_list))
		*begin_list = temp;
	else
	{
		temp->next = *begin_list;
		head = temp;
	}

}