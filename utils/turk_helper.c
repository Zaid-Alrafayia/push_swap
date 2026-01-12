/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 03:19:01 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/12 03:19:16 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	get_rotation(int len, int index)
{
	if (index <= len / 2)
		return (index);
	else
		return (index - len);
}

int	get_index(t_list *stack, int num)
{
	int	i;

	i = 0;
	while (*(int *)stack->content != num)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
