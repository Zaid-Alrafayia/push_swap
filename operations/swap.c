/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:19:03 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 09:28:10 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	sa(t_list **a, int flag)
{
	t_list	*first;
	t_list	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_list **b, int flag)
{
	t_list	*first;
	t_list	*second;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		ft_printf("ss\n");
}
