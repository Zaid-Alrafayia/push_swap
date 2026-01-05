/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:48:26 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/04 21:32:33 by zaalrafa         ###   ########.fr       */
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
	char	**numbers;
	t_list	*a;
	t_list	*b;

	a = NULL;
	numbers = check_args(argc, argv);
	a = init_stack_a(numbers);
	b = a;
	pb(&a, &b);
	ft_lstiter(b, print_content);
	ft_lstiter(a, print_content);
	return (0);
}
