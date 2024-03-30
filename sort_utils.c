/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "push_swap.h"

t_nodes *get_nodes(int discrim, t_nodes *list, int mod)
{
        if (mod == 0)
        {
                while (discrim != list->index)
                        list = list->next;
        }
        else
                while (discrim != list->value)
                        list = list->next;
        return (list);
}



void	a_find_target(t_nodes *a, t_nodes *b)
{
	int	diff;
	int	a_val;
	t_nodes	*first;

	first = b;
	while (a != NULL)
	{
		b = first;
		diff = 2147483647;
		a_val = a->value;
		while (b != NULL)
		{
			if (a_val > b->value && ((a_val - b->value) < diff))
			{
				diff = a_val - b->value;
				a->target = b;
			}
			b = b->next;
		}
		if (diff == 2147483647)
			a->target = get_nodes(max_pos(b), b, 0);
		a = a->next;
	}
}

void    b_find_target(t_nodes *a, t_nodes *b)
{
        int     diff;
        int     a_val;
        t_nodes *first;

        first = b;
        while (a != NULL)
        {
                diff = 2147483647;
                b = first;
                a_val = a->value;
                while (b != NULL)
                {
                        if (a_val < b->value && ((b->value - a_val) < diff))
                        {
                                diff = a_val - b->value;
                                a->target = b;
                        }
                        b = b->next;
                }
                if (diff == 2147483647)
                        a->target = get_nodes(min_pos(b), b, 0);
                a = a->next;
        }
}


int	push_cost(t_nodes *list)
{
	int	median;
	int	cost;

	median = ft_nblist(list) / 2;
	if (list->index <= median)
		cost = list->index;
	else
		cost = ft_nblist(list) - list->index;
	return (cost);
}

int	push_target(t_nodes *list_o)
{
	int	p_cost;
	int	min;
	int	idx_target;
	int	cost_two;

	min = 2147483647;
	idx_target = -1;
	while (list_o != NULL)
	{
		cost_two = push_cost((list_o->target));
		p_cost = push_cost(list_o) + cost_two;
		if (p_cost < min)
		{
			min = p_cost;
			idx_target = list_o->index;
		}
		list_o = list_o->next;
	}
	return (idx_target);
}
