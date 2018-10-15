#include "header.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!(lst))
		return ;
	while (lst != NULL)
	{
		(*f)(lst);
		lst = lst->next;
	}
}