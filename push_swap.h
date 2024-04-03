/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_nodes
{
	int			value;
	int			index;
	struct s_nodes	*target;
	struct s_nodes	*next;
	struct s_nodes	*prev;
}	t_nodes;



void	prt_n(t_nodes *a, t_nodes *b);

int     ft_abs(int a, int b);
t_nodes	*ft_lstlast(t_nodes *lst);
t_nodes	*ft_lstnew(int value);
void	ft_lstadd_front(t_nodes **lst, t_nodes *new);
void	ft_delfrstnode(t_nodes **lst);
void	ft_lstadd_back(t_nodes **lst, t_nodes *new);
int	ft_builder(t_nodes **a, char **argv);

t_nodes *get_nodes(int discrim, t_nodes *list, int mod);
void	a_find_target(t_nodes *a, t_nodes *b);
void    b_find_target(t_nodes *a, t_nodes *b);
int	push_cost(t_nodes *list, int len);
int	push_target(t_nodes *list_o, t_nodes *list_g);

void	do_push(t_nodes **origine, t_nodes **goal, int mod);
void	push_x(t_nodes **l_origine, t_nodes **l_goal);
void	rotate_x(t_nodes **list);
void	do_rotate(t_nodes **list, int mod);
void	do_srotate(t_nodes **list_a, t_nodes **list_b);
void	loop_rr(t_nodes **l_a, t_nodes **l_b, int a_val, int b_val);
void	rrotate_x(t_nodes **list);
void	do_rrotate(t_nodes **list, int mod);
void	do_srrotate(t_nodes **list_a, t_nodes **list_b);
void	loop_rrr(t_nodes **l_a, t_nodes **l_b, int a_val, int b_val);
void	swap_x(t_nodes **list);
void	do_swap(t_nodes **list, int mod);
void	do_sswap(t_nodes **list_a, t_nodes **list_b);

void	sort_three(t_nodes **list);
void	ft_mooving(t_nodes **a, t_nodes **b, int id_target, int mode);
void	moove(t_nodes **o, t_nodes **g, int mode);
void	sorting(t_nodes **a, t_nodes **b);

int	ft_strlen(char *s);
char	**ft_split(char *s, char c);
int     ft_atoi(char *str);
int     ft_nblist(t_nodes *list);
int	is_doublon(char **list);
int     min_pos(t_nodes *list);
int	max_pos(t_nodes *list);
int     ft_isstring(char *str);
int     is_sorted(t_nodes *list);
void	targ_on_top(t_nodes **list, int value, int mode);
void	ft_indexion(t_nodes *list);
void	free_free(char **build);

#endif
