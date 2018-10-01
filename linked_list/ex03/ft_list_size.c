#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list	*beginlist)
{
	int i;

	i = 0;
	if (!beginlist)
		return	(0);
	while (beginlist->next != NULL)
	{
		i++;
		beginlist = beginlist->next;	
	}
	return (i + 1);
}