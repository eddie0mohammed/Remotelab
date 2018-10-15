#include "header.h"
#include <stdlib.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *head;

	head = *alst;
	new->next = head;
	head = new;
}