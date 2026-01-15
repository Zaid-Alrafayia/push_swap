/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:07:08 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/15 23:07:26 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	fill_arr(t_stack *node, int len_a, int len_b, int arr[4])
{
	arr[0] = node->index;
	arr[1] = len_a - node->index;
	if (!node->target_node || len_b == 0)
	{
		arr[2] = 0;
		arr[3] = 0;
		return ;
	}
	arr[2] = node->target_node->index;
	arr[3] = len_b - node->target_node->index;
}

static int	min_from_arr(int arr[4])
{
	int	cases[4];
	int	min;
	int	i;

	if (arr[0] > arr[2])
		cases[0] = arr[0];
	else
		cases[0] = arr[2];
	if (arr[1] > arr[3])
		cases[1] = arr[1];
	else
		cases[1] = arr[3];
	cases[2] = arr[0] + arr[3];
	cases[3] = arr[1] + arr[2];
	min = cases[0];
	i = 1;
	while (i < 4)
	{
		if (cases[i] < min)
			min = cases[i];
		i++;
	}
	return (min);
}

static int	compute_min_cost(t_stack *node, int len_a, int len_b)
{
	int	arr[4];

	if (!node)
		return (0);
	fill_arr(node, len_a, len_b, arr);
	return (min_from_arr(arr));
}

void	cost_analysis_a(t_stack *a, t_stack *b)
{
	t_stack	*cur;
	int		len_a;
	int		len_b;

	if (!a)
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	cur = a;
	while (cur)
	{
		cur->push_cost = compute_min_cost(cur, len_a, len_b);
		cur = cur->next;
	}
}
