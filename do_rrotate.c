/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrotate_x(t_nodes **list)
{
	t_nodes	*last;
	t_nodes	*temp;

	if (ft_nblist((*list)) > 1)
	{
		last = ft_lstlast((*list));
		temp = (*list);
		ft_lstadd_front(list, ft_lstnew(last->value));
		while (temp->next != last)
			temp = temp->next;
		free(last);
		(temp)->next = NULL;
	}
}

void	do_rrotate(t_nodes **list, int mod)
{
	rrotate_x(list);
	if (mod == 0)
		printf("rra\n");
	else
		printf("rrb\n");
}

void	do_srrotate(t_nodes **list_a, t_nodes **list_b)
{
	rrotate_x(list_a);
	rrotate_x(list_b);
	printf("rrr\n");
}

void	loop_rrr(t_nodes **l_a, t_nodes **l_b, int a_val, int b_val)
{
	while ((*l_a)->value != a_val && (*l_b)->value != b_val)
		do_srrotate(l_a, l_b);
}
