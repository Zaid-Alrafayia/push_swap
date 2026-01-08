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
