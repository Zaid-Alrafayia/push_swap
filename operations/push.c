/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:27:00 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 09:27:36 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b, int flag)
{
	t_stack	*node;

	if (*b == NULL)
		return ;
	node = *b;
	*b = node->next;
	if (*b)
		(*b)->prev = NULL;
	node->next = *a;
	if (*a)
		(*a)->prev = node;
	node->prev = NULL;
	*a = node;
	if (flag)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int flag)
{
	t_stack	*node;

	if (*a == NULL)
		return ;
	node = *a;
	*a = node->next;
	if (*a)
		(*a)->prev = NULL;
	node->next = *b;
	if (*b)
		(*b)->prev = node;
	node->prev = NULL;
	*b = node;
	if (flag)
		ft_printf("pb\n");
}
