/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:55:35 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/15 11:07:48 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node)
		rr(a, b, 1);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node)
		rrr(a, b, 1);
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_stack **stack, t_stack *node, int flag)
{
	if (!stack || !*stack || !node)
		return ;
	while (*stack != node)
	{
		if (flag)
		{
			if (node->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else
		{
			if (node->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 1);
	prep_for_push(b, cheapest_node->target_node, 0);
	pb(a, b, 1);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 1);
	pa(a, b, 1);
}
