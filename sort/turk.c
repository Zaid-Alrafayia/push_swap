/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:16:01 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/12 03:30:48 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <limits.h>
#include <unistd.h>

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

static void	init_move(t_move **out_move)
{
	(*out_move)->cost = INT_MAX;
	(*out_move)->pos_a = 0;
	(*out_move)->pos_b = 0;
	(*out_move)->index = 0;
	(*out_move)->value = 0;
}

int	compute_cost(int pos_a, int pos_b)
{
	if ((pos_a >= 0 && pos_b >= 0) || (pos_a < 0 && pos_b < 0))
	{
		return (ft_max(ft_abs(pos_a), ft_abs(pos_b)));
	}
	else
	{
		return (ft_abs(pos_a) + ft_abs(pos_b));
	}
}

static void	find_best_move(t_list *a, t_list *b, t_move *out_move)
{
	int		len_a;
	int		len_b;
	t_list	*tmp;
	int		idx;
	t_move	curr;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	tmp = a;
	idx = 0;
	init_move(&out_move);
	while (tmp)
	{
		curr.value = *(int *)tmp->content;
		curr.index = idx;
		curr.pos_a = get_signed_rotations(len_a, curr.index);
		curr.pos_b = get_signed_rotations(len_b, find_pos_in_b(b, curr.value));
		curr.cost = compute_cost(curr.pos_a, curr.pos_b);
		if (curr.cost < out_move->cost || (curr.cost == out_move->cost
				&& abs(curr.pos_a) < abs(out_move->pos_a)))
			*out_move = curr;
		tmp = tmp->next;
		idx++;
	}
}
static void	execute_rotations_and_pb(t_list **a, t_list **b, int pos_a,
		int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		rr(a, b, 1);
		pos_a--;
		pos_b--;
	}
	while (pos_a < 0 && pos_b < 0)
	{
		rrr(a, b, 1);
		pos_a++;
		pos_b++;
	}
	while (pos_a > 0)
	{
		ra(a, 1);
		pos_a--;
	}
	while (pos_a < 0)
	{
		rra(a, 1);
		pos_a++;
	}
	while (pos_b > 0)
	{
		rb(b, 1);
		pos_b--;
	}
	while (pos_b < 0)
	{
		rrb(b, 1);
		pos_b++;
	}
	pb(a, b, 1);
}
void	turk(t_list **a, t_list **b)
{
	int		max;
	int		pos_b;
	int		min;
	int		idx;
	int		pos;
	t_move	best;

	if (ft_lstsize(*a) > 0)
		pb(a, b, 1);
	if (ft_lstsize(*a) > 0)
		pb(a, b, 1);
	while (ft_lstsize(*a) > 3)
	{
		find_best_move(*a, *b, &best);
		execute_rotations_and_pb(a, b, best.pos_a, best.pos_b);
	}
	sort_3(a);
	while (ft_lstsize(*b) > 0)
	{
		max = ft_lstmax(*b);
		idx = get_index(*b, max);
		pos_b = get_signed_rotations(ft_lstsize(*b), idx);
		while (pos_b > 0)
		{
			rb(b, 1);
			pos_b--;
		}
		while (pos_b < 0)
		{
			rrb(b, 1);
			pos_b++;
		}
		pa(a, b, 1);
	}
	min = ft_lstmin(*a);
	idx = get_index(*a, min);
	pos = get_signed_rotations(ft_lstsize(*a), idx);
	while (pos > 0)
	{
		ra(a, 1);
		pos--;
	}
	while (pos < 0)
	{
		rra(a, 1);
		pos++;
	}
}
