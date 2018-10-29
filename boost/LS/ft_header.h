#ifndef FT_HEADER_H
# define FT_HEADER_H

#include "structs.h"

int 	*check_flags(int argc, char **argv);

t_data	*ft_create_elem(void *data);
void	ft_list_push_back(t_data **begin_list, void *data);

void	ft_list_sort(t_data *begin_list);

void	ft_argc_1(char *path);




#endif