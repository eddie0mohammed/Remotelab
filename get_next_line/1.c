#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnew(size_t size);

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_memdel(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = NULL;
}

void    ft_strdel(char **as)
{
    ft_memdel((void **)as);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*ptr;

	while ((!(!line) || (ret != -1)) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ptr = s[fd];
		if (!(s[fd] = ft_strjoin(s[fd], buf)))
			s[fd] = strdup(buf);
		ft_strdel(&ptr);
	}
	if ((ret == -1 || !ft_strlen(s[fd])) && (!line || (*line = ft_strnew(0))))
		return (ret);
	ptr = strchr(s[fd], '\n');
	if (ptr && !(*ptr = '\0'))
		ptr = strdup(ptr + 1);
	else
		ptr = ft_strnew(0);
	*line = strdup(s[fd]);
	free(s[fd]);
	s[fd] = ptr;
	return (1);
}

int main(void)
{
    int fd;
	int fd1;
    char *line;
	int i;
	int j;

	line = NULL;
    if ((fd = open("file1.txt", O_RDONLY)) != -1)
    {
		while ((i = get_next_line(fd, &line)) > 0 )
		{
        	printf("%s\n", line);
		}
    }
	close(fd);
	if ((fd1 = open("file2.txt", O_RDONLY)) != -1)
	{
		while ((i = get_next_line(fd1, &line)) > 0 )
		{
			printf("%s\n", line);
		}


	}
	close(fd1);
    return (0);
}
