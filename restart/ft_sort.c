#include "ft_list.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_list_sort(t_list *begin_list)
{
	t_list *current;
	char *temp;
	t_list *forward;


	current = begin_list;
	while (current != NULL)
	{
		forward = current->next;
		while(forward != NULL)
		{
			if (ft_strcmp(current->name, forward->name) > 0)
			{
				temp = current->name;
				current->name = forward->name;
				forward->name = temp;
			}
			forward = forward->next;
		}
		current = current->next;
	}
}