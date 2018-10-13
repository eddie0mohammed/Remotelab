#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;
	t_list *head;

	head = *begin_list;

	temp = ft_create_elem(data);
	
	if (!head)
	{
		*begin_list = temp;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = temp;
	}
}
