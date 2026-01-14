/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_swap_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:07:44 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 09:31:09 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <unistd.h>

void	ra(t_stack **a, int flag)
{
	t_stack	*head;

	if (!a || !*a || !(*a)->next)
		return ;
	head = *a;
	*a = head->next;
	(*a)->prev = NULL;
	head->next = NULL;
	head->prev = NULL;
	stack_add_back(a, head);
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int flag)
{
	t_stack	*head;

	if (!b || !*b || !(*b)->next)
		return ;
	head = *b;
	*b = head->next;
	(*b)->prev = NULL;
	head->next = NULL;
	head->prev = NULL;
	stack_add_back(b, head);
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if (flag)
		ft_printf("rr\n");
}
