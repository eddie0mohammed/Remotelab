#ifndef	FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
#endif