#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*temp;

	if(!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	temp->data = data;
	temp->next = NULL;
	return (temp);
}

void	ft_printandfree(t_list **begin_list)
{
	t_list *temp;
	t_list *freedom;

	temp = *begin_list;
	while (temp)
	{
		freedom = temp;
		printf("%s\n", temp->data);
		temp = temp->next;
		free(freedom->next);
	}
}

size_t	ft_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char *str;
	size_t i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ((ft_strlen(s1)) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}