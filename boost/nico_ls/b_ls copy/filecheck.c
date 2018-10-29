/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:02:24 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/25 14:02:26 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pheader.h"
#include "lheader.h"

void file_checker(t_data **head)
{
    t_data *temp;

    if (!((*head)->next))
        return;
    temp = *head;
    struct stat stats;
    lstat((temp->name), &stats);
    if (!S_ISDIR(stats.st_mode))
    {
        b_printf("%s\t", temp->name);
        if (temp->next)
        {
            if (!(temp->last))
            {
                //if (temp)
                temp->next->last = NULL;
                *head = temp->next;
            }
        }
        else if (!(temp->next))
        {
            if (!(temp->last))
                *head = NULL;
            else
                temp->last->next = NULL;

        }
        else
        {
            temp->last->next = temp->next;
            temp->next->last = temp->last;
        }
        /*
        if (!(temp->last) || !(temp->next))
        {
            if (!(temp->last) && !(temp->next))
                return;
            if (!(temp->last))
            {
                *head = temp->next;
                (*head)->last = NULL;
            }
            else
            {   
                ;
            }
        }

        free(temp);
        temp = NULL; */
    }
    file_checker(&(*head));
}

char *time_clean(char *the_time, long numtime)
{
    char *temp;

    if ((temp = malloc(sizeof(char) * 13)) == NULL)
        return (NULL);
    temp[12] = '\0';
    if ((time(NULL) - numtime) > 15780000)
    {
        ft_strncpy(temp, (the_time + 4), 7);
        ft_strncpy((temp + 7), (the_time + 19), 5);
    }
    else
        temp = ft_strncpy(temp, (the_time + 4), 12);
    free(the_time);
    the_time = NULL;
    //gotta free the *the_time
    return (temp);
}

t_data      **t_datamaker()
{
    t_data **array;
    t_data *new_node;
    t_data *head;
    t_data *tail;

    head = NULL;
    tail = NULL;
    new_node = NULL;
    array = malloc(sizeof(t_data) * 3);
    array[0] = head;
    array[2] = tail;
    return (array);
}