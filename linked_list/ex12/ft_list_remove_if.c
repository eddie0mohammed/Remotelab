#include "ft_list.h"

void	ft_list_remove_if(t_list **beginlist, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*temp;
	t_list	*prev;

	current = *beginlist;
	temp = NULL;
	prev = NULL;
	while (current != NULL)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (current == *beginlist)
				*beginlist = current->next;
			else
				prev->next = current->next;
			temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}