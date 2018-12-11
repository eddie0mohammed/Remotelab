#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"


#include <stdio.h>


int main(int argc, char *argv[])
{
    int fd;
    t_pieces *list;

    list = init_list();
    if (((fd = open(argv[1], O_RDONLY)) == -1) || (argc != 2))
    {
        ft_putstr("usage: ./a.out file\n");
        return (0);
    }
    if (!validate_file(fd, list) || !validate_size(list))
    {
        ft_putstr("ERROR\n");
        return (0);
    }
	display_visual(list);
	reset(list);
	ft_putstr("---------------------------\n");
	ft_putstr("RESET\n");
	ft_putstr("---------------------------\n");
	display_visual(list);
	set_size_letter(list);
	solve(list);
    close(fd);
}
