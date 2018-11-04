#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int return_line(const int fd, char **line, char **hash)
{
   char *temp;
   int count;
   char *here;
   temp = hash[fd];
   count = 0;
   if ((here = strchr(temp, '\n')))
       *here = '\0';
   *line = strdup(temp);
   hash[fd] = strdup(here + 1);
   if (!(*hash[fd]))
       hash[fd] = NULL;
   free(temp);
   return (1);
}

int get_next_line(const int fd, char **line)
{
   static char    *hash[4864];
   char buf[BUFF_SIZE + 1];
   int read_amount;
   char *temp;
   char *other;

   *line = NULL;
   other = NULL;
   while ((read_amount = read(fd, buf, BUFF_SIZE)) > 0)   //change 0 to EOF???
   {
       if (!hash[fd])
       {
           other = malloc(sizeof(char));
           *other = '\0';
           hash[fd] = other;
       }
       temp = ft_strjoin(hash[fd], buf);
       if (other)
           free(other);
       hash[fd] = temp;
       if (strchr(buf, '\n'))
           break ;
   }
   if (read_amount == -1)
       return (-1);
   if (read_amount == 0 && hash[fd] == NULL)
       return (0);
   return (return_line(fd, line, hash));

}

int main(void)
{
   int fd;
   if ((fd = open("file1.txt", O_RDONLY)) == -1)
       return (0);
   char *line;
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   close(fd);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
   get_next_line(fd, &line);
   printf("%s\n", line);
}
