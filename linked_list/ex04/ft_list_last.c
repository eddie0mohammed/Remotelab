#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_last(t_list *beginlist)
{
	t_list *temp;
	temp = *beginlist;
	if (!temp)
		return (temp);
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	}
	return (temp);
}