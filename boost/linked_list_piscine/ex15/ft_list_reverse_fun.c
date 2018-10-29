#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>
void	swap_ll(t_list *a, t_list *b)
{
	void *data;

	data = a->data;
	a->data = b->data;
	b->data = data;
}

int		ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*head;

	size = 0;
	head = begin_list;
	if (!head)
		return (0);
	else
	{
		while (head)
		{
			size++;
			head = head->next;
		}
		return (size);
	}
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		length;
	int		i;s
	int		j;
	t_list	*temp;
	t_list	*swap;

	if (!begin_list)
		return ;
	temp = begin_list;
	length = ft_list_size(begin_list);
	i = 0;
	while (i <= ((length - 1) / 2))
	{
		j = 0;
		swap = begin_list;
		while (j < length - i - 1)
		{
			swap = swap->next;
			j++;
		}
		swap_ll(temp, swap);
		i++;
		temp = temp->next;
	}
}

// void	ft_list_reverse_fun(t_list *begin_list)
// {
// 	t_list *current;
// 	t_list	*prev;
// 	t_list	*follow;

// 	current = begin_list;
// 	prev = NULL;
// 	follow = NULL;

// 	while (current != NULL)
// 	{
// 		follow = current->next;
// 		current->next = prev;
// 		prev = current;
// 		current = follow;
// 	}
// 	begin_list = prev;
// }

int main()
{
	t_list *begin_list;
	t_list *one;
	t_list *two;
	t_list *three;

	begin_list = (t_list*)malloc(sizeof(t_list));
	one = (t_list*)malloc(sizeof(t_list));
	two = (t_list*)malloc(sizeof(t_list));
	three = (t_list*)malloc(sizeof(t_list));

	begin_list = one;

	one->data = "x";
	two->data = "d";
	three->data = "a";

	one->next = two;
	two->next = three;
	three->next = NULL;

	ft_list_reverse_fun(begin_list);
	while ((begin_list) != NULL)
	{
		printf("%s\n", (begin_list)->data);
		begin_list = (begin_list)->next;
	}

	return (0);
}