#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <fcntl.h>		// for open line 24
#include <sys/stat.h> // for stat line 39

#include <pwd.h>	// for uid and grp id line 65
#include <grp.h>	// for uid and grp id line 65
#include <time.h>	//
// typedef struct s_list
// {
// 	struct s_list 	*next;
// 	void			*name;
// }				t_list;

int	main(int argc, char const **argv)
{
	DIR 	 		*directory;
	struct stat		st;
	
	//time related stuff
	//time_t t ; 
    struct tm *tmp ; 
    char MY_TIME[50]; 
   
	
	struct dirent 	*rd;
	int 			fd;

	if (argc < 2)
		printf("No arguments passed.\n");
	else
	{
		if ((fd = open(argv[1], O_RDWR)) == -1)
		{
			printf("ls: %s: No such file or directory\n", argv[1]);
			return (0);
		}
		else
		{
			directory = opendir(".");
			while ((rd = readdir(directory)) != NULL)
			{
				//Name
				if (strcmp(rd->d_name, argv[1]) == 0)
				{
					printf("Name: %s\n", rd->d_name);
				
				//Type
				stat(argv[1], &st);
				if (S_ISREG(st.st_mode) && (strcmp(rd->d_name, argv[1]) == 0))
					printf("Type: File\n");
				//Modes
				printf("Modes: ");
    			printf((S_ISDIR(st.st_mode)) ? "d" : "-");
   				printf((st.st_mode & S_IRUSR) ? "r" : "-");
  				printf((st.st_mode & S_IWUSR) ? "w" : "-");
			    printf((st.st_mode & S_IXUSR) ? "x" : "-");
    			printf((st.st_mode & S_IRGRP) ? "r" : "-");
			    printf((st.st_mode & S_IWGRP) ? "w" : "-");
	    		printf((st.st_mode & S_IXGRP) ? "x" : "-");
	    		printf((st.st_mode & S_IROTH) ? "r" : "-");
	    		printf((st.st_mode & S_IWOTH) ? "w" : "-");
			    printf((st.st_mode & S_IXOTH) ? "x" : "-");
    			printf("\n");

    			//Number of links
    			printf("Number of links: %d\n",st.st_nlink);
    			//Owner			/// getpwuid
    			struct passwd *pw = getpwuid(st.st_uid);
    			printf("Owner: %s\n", pw->pw_name);
    			//Group
    			struct group  *gr = getgrgid(st.st_gid);
    			printf("Group: %s\n", gr->gr_name);
    			//Size
    			printf("Size: %lld octets\n", st.st_size);
    			//Last modification date
    			//time(&t);
    			tmp = localtime(&st.st_mtime);
    			strftime(MY_TIME, sizeof(MY_TIME), "%b %d %H:%M", tmp);
    			printf("Last modification date: %s\n", MY_TIME);

  
    			}

			}
			closedir(directory);
			
		}


	}

	return (0);
}