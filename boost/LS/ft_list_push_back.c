#include "structs.h"
#include <stdlib.h>

t_data	*ft_create_elem(void *data)
{
	t_data	*temp;

	if (!(temp = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	temp->name = data;
	temp->next = NULL;
	return (temp);
}

void	ft_list_push_back(t_data **begin_list, void *data)
{
	t_data	*head;
	t_data	*temp;

	head = *begin_list;

	temp = ft_create_elem(data);

	if (!head)
	{
		*begin_list = temp;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = temp;
	}
}