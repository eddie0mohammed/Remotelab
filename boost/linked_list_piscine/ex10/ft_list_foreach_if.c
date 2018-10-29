#include "ft_list.h"

void	ft_list_foreach_if(t_list *beginlist, void (*f)(void*), void *data_ref, int (*cmp)())
{
	while (beginlist->next != NULL)
	{
		if ((*cmp)(beginlist->data, data_ref == 0))
			(*f)(beginlist->data);
		beginlist = beginlist->next;
	}
}