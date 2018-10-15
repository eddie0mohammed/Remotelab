/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:42:37 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/28 15:42:42 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pheader.h"
#include "lheader.h"

void print_junk(t_data *head, int *flag)
{
	if (!(head))
		return;
	flag[5] = 1;
	while (head->next)
	{
		b_printf("ls: %s: No such file or directory\n", head->name);
		head = head->next;
	}
	b_printf("ls: %s: No such file or directory\n", head->name);
}

void print_files(t_data *head, t_data *tail, int *flag, t_data *other_head)
{
	if (!(head))
		return;

	flag[5] = 1;
	t_data *ptr = flag[3] ? tail : head;
	if (flag[0])
	{
	}
	else
	{
		while (flag[3] ? ptr->last : ptr->next)
		{
			b_printf("%s\n", ptr->name);
			ptr = flag[3] ? ptr->last : ptr->next;
		}
		b_printf("%s\n", ptr->name);
		if (other_head)
			b_printf("\n");
	}
}

void reg(t_data *ptr, int *flag)
{
	while (flag[3] ? ptr->last : ptr->next)
	{
		printf("%s\n", ptr->name);
		ptr = flag[3] ? ptr->last : ptr->next;
	}											//add check if for long format and print diff
	b_printf("%s\n", ptr->name); //add free after printing??
}

void	longformat(t_data *ptr, int *flag)
{
	while (flag[3] ? ptr->last : ptr->next)
	{
		printf("%s\t%s\n", ptr->time, ptr->name);
		ptr = flag[3] ? ptr->last : ptr->next;
	}											//add check if for long format and print diff
	b_printf("%s\t%s\n", ptr->time, ptr->name); //add free after printing??
}

void print_me(t_data *head, t_data *tail, int *flag)
{
	if (!(head))
		return;
	/* if (flag[5])
    {
        print_junk(head);
        flag[5] = 0;
    }*/
	// print_files();
	t_data *ptr = flag[3] ? tail : head;
	(flag[0]) ? longformat(ptr, flag) : reg (ptr, flag);
	// if (flag[0])
	// {
	// }
	// else
	// {
		// while (flag[3] ? ptr->last : ptr->next)
		// {
		// 	printf("%s\t%s\n", ptr->time, ptr->name);
		// 	ptr = flag[3] ? ptr->last : ptr->next;
		// }											//add check if for long format and print diff
		// b_printf("%s\t%s\n", ptr->time, ptr->name); //add free after printing??
		// 											//flag[6] ? 0 : b_printf("\n");
	// }
}

void run(t_data **node_dir, int *flag)
{
	if (!(node_dir[0]))
		return;
	t_data *ptr = flag[3] ? (node_dir[2]) : (node_dir[0]);

	while (flag[3] ? ptr->last : ptr->next)
	{
		if (flag[6])
			b_printf("\n");
		flag[6] = 1;

		b_printf("%s:\n", ptr->name);
		walk(ptr->name, flag);
		ptr = flag[3] ? ptr->last : ptr->next;
	}
	if (flag[5] || ptr->last || ptr->next)
		b_printf("\n%s:\n", ptr->name);
	//if ((flag[3] && ptr->last == NULL) || (!flag[3] && ptr->next == NULL))
	//	flag[6] += 1;
	walk(ptr->name, flag);
}