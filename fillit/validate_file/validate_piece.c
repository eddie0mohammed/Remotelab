/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:41:47 by medun             #+#    #+#             */
/*   Updated: 2018/11/26 13:55:51 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	helper4(int *arr)
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 19;
	arr[4] = 0;
}

int		helper3(char *buf, int *arr)
{
	if (buf[arr[1]] == '#')
	{
		if (buf[arr[1] - 1] == '#')
			arr[0]++;
		if (buf[arr[1] + 1] == '#')
			arr[0]++;
		if (buf[arr[1] - 5] == '#' && (arr[1] - 5 >= arr[4]))
			arr[0]++;
		if (buf[arr[1] + 5] == '#' && (arr[1] + 5 <= arr[3]))
			arr[0]++;
	}
	return (arr[0]);
}

int		validate_piece(char *buf, int ret)
{
	int arr[5];
	int num_blocks;

	helper4(arr);
	num_blocks = (ret / 21) + 1;
	while (arr[2] < num_blocks)
	{
		while (arr[1] < arr[3])
		{
			arr[0] = helper3(buf, arr);
			arr[1]++;
		}
		if (arr[0] == 6 || arr[0] == 8)
		{
			arr[3] += 21;
			arr[4] += 21;
			arr[0] = 0;
		}
		else
			return (-1);
		arr[2]++;
	}
	return (1);
}

//  arr[] = [count, i, j, max, min]