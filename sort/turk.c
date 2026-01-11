/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:16:01 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/11 16:28:30 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <unistd.h>

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
		i++;
	}
	return (i);
}

static int	next_cur(t_list *stackb, t_list *cur, t_list *next, int num)
{
	int	i[2];

	i[1] = ft_lstsize(stackb);
	i[0] = 0;
	while (1)
	{
		if (cur->next)
			next = cur->next;
		else
			next = stackb;
		if (*(int *)cur->content >= num && *(int *)next->content <= num)
			return (i[0] + 1 % i[1]);
		if (*(int *)cur->content < *(int *)next->content)
		{
			if (num > *(int *)cur->content && num < *(int *)next->content)
				return (i[0] + 1 % i[1]);
		}
		if (cur->next)
			cur = cur->next;
		else
			cur = stackb;
		i[0]++;
		if (cur == stackb)
			return (0);
	}
}

int	find_pos_in_b(t_list *stackb, int num)
{
	int		i;
	t_list	*next;
	t_list	*cur;

	if (!stackb)
		return (0);
	next = NULL;
	cur = stackb;
	i = next_cur(stackb, cur, next, num);
	if (!i)
		return (0);
	return (i);
}
