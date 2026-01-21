/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:03:50 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/15 11:09:13 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <unistd.h>

void	size_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_len(*a);
	if (size == 1)
		return ;
	sort_stack(a, b);
}

void	sort_3(t_stack **a)
{
	t_stack	*biggest;

	if (!*a)
		return ;
	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, 1);
	else if ((*a)->next == biggest)
		rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	while (!stack_sorted(*a) && len_a-- > 3)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}
