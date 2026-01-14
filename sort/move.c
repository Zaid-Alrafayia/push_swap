/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:55:35 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/14 20:31:51 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

void	min_to_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
}
