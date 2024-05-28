/* ******************* if (list[1] && ft_isstring(list[1]))
        {
                okou = ft_split(list[1], ' ');
if (list[1] && ft_isstring(list[1]))
        {
                okou = ft_split(list[1], ' ');******************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_abs(int a, int b)
{
	if ((a - b) > 0)
		return (a - b);
	return ((a - b) * (-1));
}

int	is_good(char **list)
{
	int		i;
	int		j;

	i = 0;
	while (list[i])
	{
		if (list[i][0] != '0' && atoi(list[i]) == 0)
			return (0);
		j = i + 1;
		while (list[j])
		{
			if (atoi(list[i]) - atoi(list[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_free(char **build)
{
	int	i;

	i = 0;
	while (build[i])
	{
		free(build[i]);
		i++;
	}
	free(build);
}

int	ft_isstring(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] < 12 && str[i] > 8))
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_nodes *list)
{
	while (list->next != NULL)
	{
		if (list->value > (list->next)->value)
			return (0);
		list = list->next;
	}
	return (1);
}
