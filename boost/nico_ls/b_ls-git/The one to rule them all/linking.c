/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:57:30 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/13 14:11:48 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define NEXT temp->next
#define T_FLAG big->flags[3]
#define NANO (temp->numtimenano - big->new_node->numtimenano)
#define TIME (temp->numtime - big->new_node->numtime)
#define NAME (ft_strcmp(big->new_node->name, temp->name))
#define NAME_OR_TIME (T_FLAG ? TIME : NAME)
#define BEFORE go_before(head, temp, big)
#define AFTER go_after(tail, temp, big)
#define PLACE_NODE(x) (x < 0) ? BEFORE : AFTER;	return (1)

int		add_link(t_data **head, t_data **tail, t_big *big)
{
	if (!(*head))
	{
		*head = big->new_node;
		*tail = big->new_node;
		return (1);
	}
	else
	{
		add_link_body(head, tail, big);
	}
	return (1);
}

int		if_nano(t_data **head, t_data **tail, t_data *temo, t_big *big)
{
	t_data *temp;

	temp = temo;
	while ((NEXT && NAME_OR_TIME == 0 && (NANO > 0)))
		temp = NEXT;
	if (NANO == 0)
	{
		while ((NEXT && NAME_OR_TIME == 0 && NANO == 0 && NAME > 0))
			temp = NEXT;
		if (NAME_OR_TIME != 0)
		{
			PLACE_NODE(NAME_OR_TIME);
		}
		if (NANO != 0)
		{
			PLACE_NODE(NANO);
		}
		PLACE_NODE(NAME);
	}
	if (NAME_OR_TIME != 0)
	{
		PLACE_NODE(NAME_OR_TIME);
	}
	PLACE_NODE(NANO);
}

int		add_link_body(t_data **head, t_data **tail, t_big *big)
{
	t_data *temp;

	temp = *head;
	while (NEXT && (NAME_OR_TIME > 0))
		temp = NEXT;
	if (T_FLAG && (NAME_OR_TIME == 0))
	{
		if_nano(head, tail, temp, big);
		return (1);
	}
	PLACE_NODE(NAME_OR_TIME);
	return (1);
}

void	go_before(t_data **head, t_data *temp, t_big *big)
{
	big->new_node->next = temp;
	big->new_node->last = temp->last;
	if (!(temp->last))
		*head = big->new_node;
	else
		temp->last->next = big->new_node;
	temp->last = big->new_node;
}

void	go_after(t_data **tail, t_data *temp, t_big *big)
{
	big->new_node->next = temp->next;
	big->new_node->last = temp;
	temp->next = big->new_node;
	if (!(big->new_node->next))
		*tail = big->new_node;
	else
		big->new_node->next->last = big->new_node;
}
