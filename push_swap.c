/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:48:26 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/11 16:31:51 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	init_stack(&a, argc, argv);
	size_sort(&a, &b);
	pb(&a, &b, 0);
	pb(&a, &b, 0);
	pb(&a, &b, 0);
	pb(&a, &b, 0);
	pb(&a, &b, 0);
	i = find_pos_in_b(b, 7);
	ft_printf("\nindex =%d\n", i);
	ft_lstiter(b, print_content);
	return (0);
}
