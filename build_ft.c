/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lstadd_back(t_nodes **lst, t_nodes *new)
{
	t_nodes	*e;

	if (!*lst)
		*lst = new;
	else
	{
		e = ft_lstlast(*lst);
		e->next = new;
		new->index = (e->index) + 1;
		new->prev = e;
	}
}

t_nodes	*ft_lstnew(int value)
{
	t_nodes	*l;

	l = (t_nodes *)malloc(sizeof(t_nodes));
	if (!l)
		return (NULL);
	l->value = value;
	l->index = 0;
	l->target = NULL;
	l->next = NULL;
	l->prev = NULL;
	return (l);
}

void	ft_lstadd_front(t_nodes **lst, t_nodes *new)
{
	new->next = *lst;
	*lst = new;
	ft_indexion(*lst);
}

t_nodes	*ft_lstlast(t_nodes *lst)
{
	t_nodes *temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_delfrstnode(t_nodes **lst)
{
	t_nodes	*temp;

	if (lst == NULL || *lst == NULL)
		return;
	temp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	ft_indexion((*lst));
	free(temp);
}

