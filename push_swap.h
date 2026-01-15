/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:30:49 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/15 23:07:56 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
// arg.c
char				**split_args(int argc, char **argv);
void				check_repeat(char **numbers, int split);
void				validate_chars(char **numbers, int split);
// argc2.c
void				add_to_stack(t_stack **a, char **numbers, char **original,
						int split);
void				overflow(char **num, int split);
void				init_stack(t_stack **a, int argc, char **argv);
// swap.c
void				sa(t_stack **a, int flag);
void				sb(t_stack **b, int flag);
void				ss(t_stack **a, t_stack **b, int flag);
// push.c
void				pa(t_stack **a, t_stack **b, int flag);
void				pb(t_stack **a, t_stack **b, int flag);
// rotate.c
void				ra(t_stack **a, int flag);
void				rb(t_stack **b, int flag);
void				rr(t_stack **a, t_stack **b, int flag);
// rrotate.c
void				rra(t_stack **a, int flag);
void				rrb(t_stack **b, int flag);
void				rrr(t_stack **a, t_stack **b, int flag);

// rrotate.c

// helper.c
void				free_split(char **arr);
void				rotate_to_top(t_stack **stack, int index);
int					get_signed_rotations(int len, int idx);
int					get_value_at_index(t_stack *lst, int idx);

// stack helpers
t_stack				*stack_new(int nbr);
void				stack_add_back(t_stack **stack, t_stack *new_node);
void				stack_clear(t_stack **stack);
// error.c
void				split_error(char **numbers, int split);
void				free_error(char **numbers);
void				errp(void);
// a_is_sorted.c
int					a_is_sorted(t_stack **a);
void				find_two_smallest(t_stack *head, int mins[2], int idxs[2]);
t_stack				*find_max(t_stack *a);
// size_sort.c
void				size_sort(t_stack **a, t_stack **b);
void				sort_1(t_stack **a);
void				sort_2(t_stack **stacka);
void				sort_3(t_stack **a);
void				sort_stack(t_stack **stacka, t_stack **stackb);
// utils.c

int					stack_len(t_stack *stack);
t_stack				*find_last(t_stack *stack);
bool				stack_sorted(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);
// init.c
void				current_index(t_stack *s);
void				init_nodes_a(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *stack);
// move.c
void				move_a_to_b(t_stack **a, t_stack **b);
void				move_b_to_a(t_stack **a, t_stack **b);
void				prep_for_push(t_stack **stack, t_stack *node, int flag);
// functions.c
t_stack				*get_cheapest(t_stack *stack);
void				min_to_top(t_stack **a);
void				print_stack(t_stack *stack);
// cost.c
void				cost_analysis_a(t_stack *a, t_stack *b);
// init_b.c
void				init_nodes_b(t_stack *a, t_stack *b);
#endif // !PUSH_SWAP_H
