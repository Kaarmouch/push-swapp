/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	targ_on_top(t_nodes **list, int value, int mode)
{
	int	len_l;
	t_nodes	*info;
	
	info = get_nodes(value, (*list), 1);
	len_l = ft_nblist((*list));
	if (info->index <= (len_l / 2))
	{
		while ((*list)->value != value)
			do_rotate(list, mode);
	}
	else
	{
		while ((*list)->value != value)
			do_rrotate(list, mode);
	}
}

int	max_pos(t_nodes *list)
{
	int	max;
	int	max_id;
	
	max = -2147483647;
	while (list)
	{
		if (max < list->value)
		{
			max = list->value;
			max_id = list->index;
		}
		list = list->next;
	}
	return (max_id);
}

int     min_pos(t_nodes *list)
{
        int     min;
        int     min_id;

        min = 2147483647;
        while (list)
        {
                if (min > list->value)
                {
                        min = list->value;
                        min_id = list->index;
                }
                list = list->next;
        }
        return (min_id);
}

void	ft_indexion(t_nodes *list)
{
	int	i;
	i = 0;
	while (list)
	{
		list->index = i;
		list = list->next;
		i++;
	}
}

int     ft_nblist(t_nodes *list)
{
        int     i;
        i = 0;
        if (list)
                i = 1;
        while (list && list->next != NULL)
        {
                list = list->next;
                i++;
        }
        return (i);
}
