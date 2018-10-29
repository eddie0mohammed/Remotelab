#include "ft_list.h"
#include <stdio.h>

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int i;

// 	i = 0;
// 	while (s1[i] != '\0' || s2[i] != '\0')
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	void	*temp;
	t_list	*forward;


	current = *begin_list;
	while (current->next != NULL)
	{
		forward = current->next;
		while(forward != NULL)
		{
			if ((*cmp)(current->data, forward->data) > 0)
			{
				temp = current->data;
				current->data = forward->data;
				forward->data = temp;
			}
			forward = forward->next;
		}
		current = current->next;
	}
}

// int	main()
// {
// 	t_list	**begin_list;
// 	t_list	*one;
// 	t_list 	*two;
// 	t_list 	*three;
// 	t_list 	*four;

// 	begin_list = (t_list**)malloc(sizeof(t_list) * 4);
// 	*begin_list = (t_list*)malloc(sizeof(t_list));
// 	one = (t_list*)malloc(sizeof(t_list));
// 	two = (t_list*)malloc(sizeof(t_list));
// 	three = (t_list*)malloc(sizeof(t_list));
// 	four = (t_list*)malloc(sizeof(t_list));

// 	*begin_list = one;

// 	one->data = "x";
// 	two->data = "d";
// 	three->data = "a";
// 	four->data = "i";
// 	one->next = two;
// 	two->next = three;
// 	three->next = four;
// 	four->next = NULL;

// 	ft_list_sort(begin_list);

// 	while ((*begin_list) != NULL)
// 	{
// 		printf("%s\n", (char*)(*begin_list)->data);
// 		*begin_list = (*begin_list)->next;
// 	}
// 	return (0);
// }