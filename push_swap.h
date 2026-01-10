/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:30:49 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 10:35:13 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// arg.c
char	**split_args(int argc, char **argv);
void	check_repeat(char **numbers, int split);
void	validate_chars(char **numbers, int split);
// argc2.c
void	add_to_stack(t_list **a, char **numbers, char **original, int split);
void	overflow(char **num, int split);
void	init_stack(t_list **a, int argc, char **argv);
// swap.c
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
// push.c
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
// rotate.c
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

// rrotate.c
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// helper.c
void	free_split(char **arr);
void	rotate_to_top(t_list **stack, int index);
// error.c
void	split_error(char **numbers, int split);
void	free_error(char **numbers);
void	errp(void);
// a_is_sorted.c
int		a_is_sorted(t_list **a);
void	find_two_smallest(t_list *head, int mins[2], int idxs[2]);
// size_sort.c
void	size_sort(t_list **a, t_list **b);
void	sort_1(t_list **a);
void	sort_2(t_list **stacka);
void	sort_3(t_list **a);
void	sort_5(t_list **stacka, t_list **stackb);

#endif // !PUSH_SWAP_H
