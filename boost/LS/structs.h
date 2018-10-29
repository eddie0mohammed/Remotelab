#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct 		s_data
{
	char			*name;
	char			*time;
	char			*mode;
	char			*owner;
	char			*group;
	long long		size;
	unsigned short	links;
	struct s_data	*next;	
}					t_data;

#endif