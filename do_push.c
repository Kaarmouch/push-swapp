/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_x(t_nodes **l_origine, t_nodes **l_goal)
{
	if (ft_nblist((*l_origine)) >= 1)
	{
		ft_lstadd_front(l_goal, ft_lstnew((*l_origine)->value));
		ft_indexion((*l_goal));
		ft_delfrstnode(l_origine);
	}
}

void	do_push(t_nodes **origine, t_nodes **goal, int mod)
{
	push_x(origine, goal);
	if (mod == 0)
		printf("pa\n");
	else
		printf("pb\n");
}
