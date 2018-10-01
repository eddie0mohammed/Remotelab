#include "ft_list.h"

void	ft_list_merge(t_list **beginlist1, t_list *beginlist2)
{
	t_list	*current;

	if (*beginlist1)
	{
		current = *beginlist1;
		while (current->next != NULL)
			current = current->next;
		curret->next = beginlist2;
	}
	else
	{
		*beginlist1 = beginlist2;
	}
}