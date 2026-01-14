/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 01:05:44 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/13 21:41:59 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_stack	*stack_new(int nbr)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->index = -1;
	node->push_cost = 0;
	node->above_median = false;
	node->cheapest = false;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*cur;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}

int	stack_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

void	rotate_to_top(t_stack **stack, int index)
{
	int	size;
	int	rot;

	size = stack_size(*stack);
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(stack, 1);
	}
	else
	{
		rot = size - index;
		while (rot-- > 0)
			rra(stack, 1);
	}
}

int	get_signed_rotations(int len, int index)
{
	if (len <= 0)
		return (0);
	index = index % len;
	if (index < 0)
		index += len;
	if (index <= len / 2)
		return (index);
	return (index - len);
}

int	get_value_at_index(t_stack *lst, int idx)
{
	int	i;

	i = 0;
	while (lst && i < idx)
	{
		lst = lst->next;
		i++;
	}
	return (lst->nbr);
}
