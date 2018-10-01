#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*temp;

	i = 0;
	head = NULL;
	if (ac != 2)
		return (NULL);
	else
	{
		while (i < ac)
		{
			temp = ft_create_elem((char*)av[i]);
			temp->next = head;
			head = temp;
			i++;
		}
	}
	return (head);
}