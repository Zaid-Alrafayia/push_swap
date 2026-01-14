/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:43:04 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/14 03:02:50 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <limits.h>

int	a_is_sorted(t_stack **a)
{
	t_stack	*cur;

	if (!a || !*a)
		return (1);
	cur = *a;
	while (cur->next)
	{
		if (cur->nbr > cur->next->nbr)
			return (0);
		cur = cur->next;
	}
	return (1);
}
