#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*Next;
	t_list	*current;
	t_list	*prev;

	Next = NULL;
	prev = NULL;
	current = *begin_list;
	if (!(begin_list))
		return (NULL);
	while (current != NULL)
	{
		Next = current->next;
		current->next = prev;
		prev = current;
		current = Next;		
	}
	*begin_list = prev;
}