/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:47:20 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/15 11:10:25 by zaalrafa         ###   ########.fr       */
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
	if (!*a)
		return ;
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a))
			ra(a, 1);
		else
			rra(a, 1);
		*a = (*a)->next;
	}
}

void	print_content(void *content)
{
	int	*num;

	num = (int *)content;
	ft_printf("%d\n", *num);
}
