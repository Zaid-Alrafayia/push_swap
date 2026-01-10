/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_is_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:43:04 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 09:46:13 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <limits.h>

int	a_is_sorted(t_list **a)
{
	while ((*a)->next != NULL)
	{
		if ((*a)->content > (*a)->next->content)
			return (0);
		*a = (*a)->next;
	}
	return (1);
}

void	find_two_smallest(t_list *head, int mins[2], int idxs[2])
{
	int	i;
	int	v;

	mins[0] = INT_MAX;
	mins[1] = INT_MAX;
	idxs[0] = -1;
	idxs[1] = -1;
	i = 0;
	while (head)
	{
		v = *(int *)head->content;
		if (v < mins[0])
		{
			mins[1] = mins[0];
			idxs[1] = idxs[0];
			mins[0] = v;
			idxs[0] = i;
		}
		else if (v < mins[1])
		{
			mins[1] = v;
			idxs[1] = i;
		}
		head = head->next;
		i++;
	}
}
