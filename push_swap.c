/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:48:26 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/15 11:03:29 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	init_stack(&a, argc, argv);
	size_sort(&a, &b);
	// ft_lstiter(a, print_content);
	stack_clear(&a);
	return (0);
}
