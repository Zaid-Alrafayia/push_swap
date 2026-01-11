/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:03:50 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 12:14:19 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <unistd.h>

void	size_sort(t_list **a, t_list **b)
{
	int	n;

	n = ft_lstsize(*a);
	if (n == 1)
		sort_1(a);
	else if (n == 2)
		sort_2(a);
	else if (n == 3)
		sort_3(a);
	else if (n <= 5)
		sort_5(a, b);
	else
		turk(a, b);
}

void	sort_1(t_list **a)
{
	ft_lstclear(a, free);
	exit(1);
}

void	sort_2(t_list **stacka)
{
	if ((*stacka)->content < (*stacka)->next->content)
		ra(stacka, 1);
	else
		exit(1);
}

void	sort_3(t_list **stacka)
{
	int	*a;
	int	*b;
	int	*c;

	a = (*stacka)->content;
	b = (*stacka)->next->content;
	c = (*stacka)->next->next->content;
	if (*a > *b && *b > *c && *a > *c)
	{
		sa(stacka, 1);
		rra(stacka, 1);
	}
	else if ((*a > *b) && (*b < *c) && (*a > *c))
		ra(stacka, 1);
	else if ((*a < *c) && (*a < *b) && (*c < *b))
	{
		ra(stacka, 1);
		sa(stacka, 1);
		rra(stacka, 1);
	}
	else if ((*a > *b) && (*b < *c) && (*a < *c))
		sa(stacka, 1);
	else if ((*a < *b) && (*b > *c) && (*a > *c))
		rra(stacka, 1);
}

void	sort_5(t_list **stacka, t_list **stackb)
{
	int	min_vals[2];
	int	min_idxs[2];
	int	size;

	size = ft_lstsize(*stacka);
	if (size == 5)
	{
		find_two_smallest(*stacka, min_vals, min_idxs);
		rotate_to_top(stacka, min_idxs[0]);
		pb(stacka, stackb, 1);
	}
	find_two_smallest(*stacka, min_vals, min_idxs);
	rotate_to_top(stacka, min_idxs[0]);
	pb(stacka, stackb, 1);
	sort_3(stacka);
	pa(stacka, stackb, 1);
	pa(stacka, stackb, 1);
}
