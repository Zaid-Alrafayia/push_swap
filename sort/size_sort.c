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

void	size_sort(t_list **a)
{
	int	n;

	n = ft_lstsize(*a);
	if (n == 2)
		sort_1(a);
	else if (n == 3)
		sort_3(a);
	else if (n <= 5)
		sort_5(a);
	//	else
	//		turk(a);
}

void	sort_1(t_list **a)
{
	ft_lstclear(a, free);
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
		sa(stacka);
		rra(stacka);
	}
	else if ((*a > *b) && (*b < *c) && (*a > *c))
		ra(stacka);
	else if ((*a < *c) && (*a < *b) && (*c < *b))
	{
		ra(stacka);
		sa(stacka);
		rra(stacka);
	}
	else if ((*a > *b) && (*b < *c) && (*a < *c))
		sa(stacka);
	else if ((*a < *b) && (*b > *c) && (*a > *c))
		rra(stacka);
}

void	sort_5(t_list **stacka)
{
	t_list	*head;
	int		min;
	int		min2;
	int		i;
	int		index[2];
	int		x;

	i = 0;
	head = *stacka;
	min = *(int *)head->content;
	index[0] = 0;
	index[1] = 0;
	min2 = *(int *)head->next->content;
	while (head != NULL)
	{
		x = *(int *)head->content;
		if (min > x)
		{
			min2 = min;
			index[1] = index[0];
			min = x;
			index[0] = i;
		}
		else if ((min < x) && (x < min2))
		{
			min2 = x;
			index[1] = i;
		}
		head = head->next;
		i++;
	}
	ft_printf("min:%d = index:%d\nmin2:%d = index:%d\n", min, index[0], min2,
		index[1]);
}
