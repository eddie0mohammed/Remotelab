#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// int		main(void)
// {
// 	int i;

// 	i = 0;
// 	while (i < 6)
// 	{
// 		printf("%d\t", (rand() % (70 - 1 + 1) + 1));
// 		printf("%d\t", (rand() % (70 - 1 + 1) + 1));
// 		printf("%d\t", (rand() % (70 - 1 + 1) + 1));
// 		printf("%d\t", (rand() % (70 - 1 + 1) + 1));
// 		printf("%d\t", (rand() % (70 - 1 + 1) + 1));
// 		printf("%d\t", (rand() % (70 - 1 + 1) + 1));
// 		//printf("%d\t", (rand() % (70 - 1 + 1) + 1));
// 		printf("%d\n", (rand() % (70 - 1 + 1) + 1));

// 		i++;
// 	} 

// 	return (0);
// }

int main () {
   int i, j, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 50 */
   for ( j = 0; j < 5 ; j++)
	{
	   for( i = 0 ; i < n ; i++ )
	    {
    	  printf("%d  ", rand() % (70 - 1 + 1) + 1);
    	}
    	printf("%d  ", rand() % (25 - 1 + 1) + 1);
   
   		printf("\n");
   	}
   return(0);
}