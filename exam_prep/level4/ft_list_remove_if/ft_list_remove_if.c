#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list 	*temp;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	current = *begin_list;
	while (current && current->next)
	{
		if (!cmp(current->next->data, data_ref))
		{
			temp = current->next;
			current->next = temp->next;
			free(temp);
		}
		if (current->next)
			current = current->next;
	}
}