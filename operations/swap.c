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

void	sa(t_stack **a, int flag)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_nbr;
	int		tmp_index;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	tmp_nbr = first->nbr;
	tmp_index = first->index;
	first->nbr = second->nbr;
	first->index = second->index;
	second->nbr = tmp_nbr;
	second->index = tmp_index;
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int flag)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_nbr;
	int		tmp_index;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	tmp_nbr = first->nbr;
	tmp_index = first->index;
	first->nbr = second->nbr;
	first->index = second->index;
	second->nbr = tmp_nbr;
	second->index = tmp_index;
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		ft_printf("ss\n");
}
