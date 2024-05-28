/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_nodes(t_nodes *nodes)
{
	t_nodes	*flag;

	flag = nodes->next;
	while (flag != NULL)
	{
		free(nodes);
		nodes = flag;
		flag = nodes->next;
	}
	free(nodes);
}

int	ft_test(char **list)
{
	char	**okou;

	if (list[1] && ft_isstring(list[1]))
        {
                okou = ft_split(list[1], ' ');
		if (is_good(okou) == 0)
		{
			free_free(okou);
			return (0);
		}
		else
		{
			free_free(okou);
			return (1);
		}
	}
	else if (!is_good(&list[1]))
			return (0);
	return (1);
}

int	ft_builder(t_nodes **a, char **argv)
{
	char	**okou;
	int		i;

	if (argv[1] && ft_isstring(argv[1]))
	{
		okou = ft_split(argv[1], ' ');
		i = 0;
		while (okou[i])
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(okou[i])));
			i++;
		}
		free_free(okou);
		return (1);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
		return (1);
	}
}

void	ft_print(t_nodes *a, t_nodes *b)
{
	printf("\nA\n");
	while (a)
	{
		printf("%d\n", a->value);
		a=a->next;
	}
	if (b)
	{
		printf("\nB\n");
		while (b)
		{
			printf("%d\n",b->value);
			b=b->next;
		}
        }
        printf("\n");
}

int	main(int argc, char **argv)
{
	t_nodes	*a_node;
	t_nodes	*b_node;

	if (argc == 1)
		return (0);
	if ((argc < 2 && argv[1] != NULL) || !ft_test(argv))
	{
		write(1,"Error\n", 6);
		return (0);
	}
	a_node = NULL;
	b_node = NULL;
	if (!(ft_builder(&a_node, argv)))
		return (0);
	if (!(is_sorted(a_node)))
	{
		if (ft_nblist(a_node) == 2)
			do_swap(&a_node, 0);
		else if (ft_nblist(a_node) == 3)
			sort_three(&a_node);
		else
			sorting(&a_node, &b_node);
	}
	free_nodes(a_node);
	return (0);
}
