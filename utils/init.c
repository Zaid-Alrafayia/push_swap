/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:02:54 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/15 23:18:20 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <stdbool.h>

void	current_index(t_stack *stack)
{
	t_stack	*cur;
	int		i;
	int		median;

	cur = stack;
	i = 0;
	if (!cur)
		return ;
	median = stack_len(cur) / 2;
	while (cur)
	{
		cur->index = i;
		cur->above_median = (i <= median);
		cur = cur->next;
		++i;
	}
}

static void	set_target_a(t_stack *a, t_stack *b, long best_val)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	t_stack	*best;

	cur_a = a;
	while (cur_a)
	{
		best = NULL;
		best_val = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->nbr < cur_a->nbr && cur_b->nbr > best_val)
			{
				best_val = cur_b->nbr;
				best = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best == NULL)
			cur_a->target_node = find_max(b);
		else
			cur_a->target_node = best;
		cur_a = cur_a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	long	best_val;

	best_val = LONG_MIN;
	current_index(a);
	current_index(b);
	set_target_a(a, b, best_val);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
