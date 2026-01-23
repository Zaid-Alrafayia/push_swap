/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:42:05 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/16 00:58:37 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <stdlib.h>

int	move_condetions(t_stack **a, t_stack **b, char *move)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		return (-1);
	return (0);
}

int	read_move(t_stack **a, t_stack **b)
{
	char	*move;
	int		x;

	move = get_next_line(0);
	x = 0;
	while (move && move[0] != '\n')
	{
		x = move_condetions(a, b, move);
		if (x == -1)
		{
			free(move);
			return (-1);
		}
		free(move);
		move = get_next_line(0);
	}
	free(move);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		x;

	a = NULL;
	b = NULL;
	if (!argv[1])
		return (0);
	init_stack(&a, argc, argv);
	x = read_move(&a, &b);
	if (stack_sorted(a))
		ft_printf("OK\n");
	else if (x == -1)
		ft_printf("Error\n");
	else
		ft_printf("KO\n");
	stack_clear(&a);
	return (0);
}
