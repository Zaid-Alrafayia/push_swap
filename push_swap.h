/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:30:49 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/06 11:31:10 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// arg.c
void	free_error(char **numbers);
void	errp(void);
void	init_stack(t_list **a, int argc, char **argv);
char	**check_args(int argc, char **argv);
void	overflow(char **num);

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
#endif // !PUSH_SWAP_H
