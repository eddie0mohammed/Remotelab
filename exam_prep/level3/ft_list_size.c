#include "ft_list_size.h"
#include <stdlib.h>

int		ft_list_size(t_list *begin_list)
{
	int i = 0;
	t_list	*ptr;

	ptr = begin_list;
	
	while (ptr != NULL)
	{
		i++;
		*ptr = begin_list->next;
	}
	return (i);
}