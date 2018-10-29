#include "ft_list.h"

void	ft_list_clear(t_list **beginlist)
{
	t_list	*current;
	t_list	*temp;

	current = *beginlist;
	temp = *beginlist;
	if (!current)
		return ;

	while (current->next != NULL)
	{
		current = current->next;
		free(temp);
		temp = current;
	}
	*beginlist = NULL;
}