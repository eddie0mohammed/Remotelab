#include "includes/header.h"
#include <stdlib.h>
#include <stdio.h>

t_list 	*calculate_width_height(char *buf, t_list *list)
{
	int width;
	int height;
	int i;
	int ncount;

	width = 1;
	height = 1;
	i = 0;
	ncount = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				ncount++;
			if (buf[i - 1] == '#')
				ncount++;
			if (buf[i + 5] == '#')
				ncount++;
			if (buf[i - 5] == '#')
				ncount++;
		}
		if (buf[i] == '#' && buf[i + 1] == '#')
			width++;
		if (buf[i] == '#' && buf[i + 5] == '#')
			height++;
		i++;
	}
	if (ncount == 8)
	{
		width--;
		height--;
	}
	list = ft_list_push_back(&list, height, width, buf);
	// ft_putstr(buf);
	// ft_putstr("\n");
	// printf("width = %d\n", width);
	// printf("height = %d\n", height);
	// printf("ncount = %d\n", ncount);
	// printf("======================\n");
	free(buf);
	return (list);
}

//////////////////////////////////////////////////////////////////
t_list	*get_w_h_of_all_file(char *buf)
{
	int i = 0;
	//int blocks = 0;
	char *block;
	int ret = 0;
	int num_blocks;
	int j = 0;
	int max = 19;
	int min = 0;
	int piece_count = 1;
	t_list 	*list;

	list = NULL;
	while (buf[ret])
		ret++;
	ret++;
	num_blocks = (ret / 21 + 1);
	// printf("ret: %d\n", ret);
	// printf("num_blocks: %d\n", num_blocks);

	while (j < num_blocks)
	{
		if(!(block = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		while (min < max)
		{
			block[i] = buf[min];
			i++;
			min++;
		}
		block[i] = '\0';
		
		// printf("\npiece %d:\n", piece_count);
		// piece_count++;
		//ft_putstr(block);
		//printf("\n");
		list = calculate_width_height(block, list);
		j++;
		max += 21;
		min += 2;
		i = 0;
	}
	//printf("TEST++++++++++++++++++++++++++++++++++++++\n\n\n");
	// while (list)
	// {
	// 	printf("height = %d\n", list->ht);
	// 	printf("width = %d\n", list->wd);
	// 	ft_putstr(list->piece);
	// 	printf("\n=======================\n");
	// 	list = list->next;
	// }
	return (list);
}