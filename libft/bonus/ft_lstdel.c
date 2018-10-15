#include "header.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *head;
	t_list *pointer;

	head = *alst;
	
	if (!alst || !*alst)
		return ;
	while (head != NULL)
	{
		pointer = head->next;
		del(pointer.content, pointer->content_size);
		free(pointer);
		head = pointer;

	}
	*alst = NULL;
}