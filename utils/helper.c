/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 01:05:44 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 09:52:12 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	rotate_to_top(t_list **stack, int index)
{
	int	size;
	int	rot;

	size = ft_lstsize(*stack);
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(stack, 1);
	}
	else
	{
		rot = size - index;
		while (rot-- > 0)
			rra(stack, 1);
	}
}
