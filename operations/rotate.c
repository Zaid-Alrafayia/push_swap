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

void	ra(t_list **a)
{
	t_list	*head;

	head = *a;
	*a = (*a)->next;
	head->next = NULL;
	ft_lstadd_back(a, head);
}

void	rb(t_list **b)
{
	t_list	*head;

	head = *b;
	*b = (*b)->next;
	head->next = NULL;
	ft_lstadd_back(b, head);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
