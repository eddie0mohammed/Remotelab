#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	struct s_list 	*next;
	void			*name;
}				t_list;









int	ft_strcmp(char *s1, char *s2);
void	ft_list_sort(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_create_elem(void *data);
void	ft_printandfree(t_list **begin_list);
size_t	ft_strlen(const char *s1);
char	*ft_strdup(const char *s1);
void	ft_list_clear(t_list **begin_list);

#endif