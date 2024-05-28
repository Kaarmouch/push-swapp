/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_x(t_nodes **list)
{
	t_nodes	*temp;
	int		temp_v;

	if (ft_nblist((*list)) > 1)
	{
		temp = (*list)->next;
		temp_v = temp->value;
		temp->value = (*list)->value;
		(*list)->value = temp_v;
	}
}

void	do_swap(t_nodes **list, int mod)
{
	swap_x(list);
	if (mod == 0)
		printf("sa\n");
	else
		printf("sb\n");
}

void	do_sswap(t_nodes **list_a, t_nodes **list_b)
{
	swap_x(list_a);
	swap_x(list_b);
	printf("ss");
}
