/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_swap_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:07:44 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/05 23:55:09 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"
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
