/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:30:49 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/07 00:36:54 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// arg.c
char	**split_args(int argc, char **argv);
void	check_repeat(char **numbers, int split);
void	validate_chars(char **numbers, int split);
// argc2.c
void	add_to_stack(t_list **a, char **numbers, char **original, int split);
void	overflow(char **num, int split);
void	init_stack(t_list **a, int argc, char **argv);
// push_swap_funct.c
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
// more_swap_funct.c
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// helper.c
void	free_split(char **arr);

// error.c
void	split_error(char **numbers, int split);
void	free_error(char **numbers);
void	errp(void);

#endif // !PUSH_SWAP_H
