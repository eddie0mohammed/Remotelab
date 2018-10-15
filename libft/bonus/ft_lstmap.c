#include <stdlib.h>
#include "header.h"

t_list		*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = (*f)(lst);
	new_list = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = (*f)(lst);
		temp = temp->next;
	}
	return (new_list);
}