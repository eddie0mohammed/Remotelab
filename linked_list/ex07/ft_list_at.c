#include "ft_list.h"

t_list	*ft_list_at(t_list *beginlist unsigned int nbr)
{
	t_list			*current;
	unsigned int	i;
	
	i = 0;
	current  = beginlist;
	if (!beginlist)
	{
		current = NULL;
		return (current)
	}
	else if (!nbr)
		return (beginlist);
	else
	{
		while (i != nbr)
		{
			current = current->next;
			i++;
		}
	}
	return (current);
}