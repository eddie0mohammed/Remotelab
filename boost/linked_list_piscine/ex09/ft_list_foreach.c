#include "ft_list.h"

void	ft_list_foreach(t_list *beginlist, void (*f)(void*))
{
	t_list	*current;

	current = beginlist;
	while (current->next != NULL)
	{
		(*f)(current->data);
		current = current->next;
	}
}