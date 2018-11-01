int return_line(const int fd, char **line, char **hash)
{
   char *temp;
   int count;
   char *here;
   temp = hash[fd];
   count = 0;
   here = temp;
   if ((here = strchr(temp, ‘\n’)))
       *here = ‘\0’;
   *line = ft_strdup(temp);
   hash[fd] = ft_strdup(here + 1);
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

   while ((read_amount = read(fd, buf, BUFF_SIZE)) > 0)
   {
       if (!hash[fd])
       {
           other = malloc(sizeof(char));
           *other = ‘\0’;
           hash[fd] = other;
       }
       temp = ft_strjoin(hash[fd], buf);
       if (other)
           free(other);
       hash[fd] = temp;
       if (strchr(buf, ‘\n’))
           break ;
   }
   if (read_amount == -1)
       return (-1);
   if (read_amount == 0 && hash[fd] == NULL)
       return (0);
   return (return_line(fd, line, hash));

}