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

void	rra(t_list **a)
{
	t_list	*tmp;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_list **b)
{
	t_list	*tmp;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	tmp = *b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
