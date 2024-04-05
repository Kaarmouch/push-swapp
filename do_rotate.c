/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_x(t_nodes **list)
{
	ft_lstadd_back(list, ft_lstnew((*list)->value));
	ft_delfrstnode(list);
}

void	do_rotate(t_nodes **list, int mod)
{
	rotate_x(list);
	if (mod == 0)
		printf("ra\n");
	else
		printf("rb\n");
}

void	do_srotate(t_nodes **list_a, t_nodes **list_b)
{
	rotate_x(list_a);
	rotate_x(list_b);
	printf("rr");
}

void	loop_rr(t_nodes **l_a, t_nodes **l_b, int a_val, int b_val)
{
	while ((*l_a)->value != a_val && (*l_b)->value != b_val)
		do_srotate(l_a, l_b);
}
