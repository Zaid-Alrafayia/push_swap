/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:31:25 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 09:31:41 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*tail;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	if (tail->prev)
		tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *a;
	(*a)->prev = tail;
	*a = tail;
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*tail;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	if (tail->prev)
		tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *b;
	(*b)->prev = tail;
	*b = tail;
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag)
		ft_printf("rrr\n");
}
