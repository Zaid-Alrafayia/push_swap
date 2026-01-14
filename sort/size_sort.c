/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:03:50 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/14 20:31:53 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <unistd.h>

void	size_sort(t_stack **a, t_stack **b)
{
	int	n;

	n = stack_len(*a);
	if (n == 1)
		sort_1(a);
	else if (n == 2)
		sort_2(a);
	else if (n == 3)
		sort_3(a);
	else
		sort_stack(a, b);
}

void	sort_1(t_stack **a)
{
	(void)a;
	return ;
}

/* two elements: swap if out of order */
void	sort_2(t_stack **stacka)
{
	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	if ((*stacka)->nbr > (*stacka)->next->nbr)
		sa(stacka, 1);
}

void	sort_3(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, false);
	else if ((*a)->next == biggest)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
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
	min_on_top(a);
}
