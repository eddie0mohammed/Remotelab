#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list	**begin_list, void	*data)
{
	t_list	*head
	t_list	*temp;

	head = *begin_list;
	if (!head)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	else
	{
		temp = ft_create_elem(data);
		temp->next = *begin_list;
		*begin_list = temp;
	}
}