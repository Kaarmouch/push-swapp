/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_nodes **list)
{
	int	mx_pos;

	mx_pos = max_pos(*list);
	if (mx_pos == 0)
		do_rotate(list, 0);
	else if (mx_pos == 1)
		do_rrotate(list, 0);
	if ((*list)->value > ((*list)->next)->value)
		do_swap(list, 0);
}

void	ft_mooving(t_nodes **a, t_nodes **b, int id_target, int mode)
{
	t_nodes	*p_a;
	int		med_a;
	int		med_b;
	int		a_val;
	int		b_val;

	med_a = ft_nblist(*a);
	med_b = ft_nblist(*b);
	p_a = get_nodes(id_target, *a, 0);
	a_val = p_a->value;
	b_val = (p_a->target)->value;
	if (p_a->index > med_a && (p_a->target)->index > med_b)
		loop_rr(a, b, a_val, b_val);
	else if (p_a->index < med_a && (p_a->target)->index < med_b)
		loop_rrr(a, b, a_val, b_val);
	targ_on_top(a, a_val, mode);
	targ_on_top(b, b_val, mode);
}

void	moove(t_nodes **o, t_nodes **g, int mode)
{
	int	target_index;

	if (mode == 1)
		a_find_target((*o), (*g));
	else if (mode == 0)
		b_find_target((*o), (*g));
	target_index = push_target((*o));
	ft_mooving(o, g, target_index, mode);
	do_push(o, g, mode);
}

void	sorting(t_nodes **a, t_nodes **b)
{
	do_push(a, b, 1);
	if (ft_nblist((*a)) > 3 && (!(is_sorted((*a)))))
		do_push(a, b, 1);
	while (ft_nblist((*a)) > 3 && !(is_sorted((*a))))
		moove(a, b, 1);
	sort_three(a);
	while ((*b))
		moove(b, a, 0);
}
