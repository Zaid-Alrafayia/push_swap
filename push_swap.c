/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:48:26 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 10:35:35 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_content(void *content)
{
	int	*num;

	num = (int *)content;
	ft_printf("%d\n", *num);
}

int	main(int argc, char *argv[])
{
	t_list	*a;

	a = NULL;
	init_stack(&a, argc, argv);
	size_sort(&a);
	ft_lstiter(a, print_content);
	return (0);
}
