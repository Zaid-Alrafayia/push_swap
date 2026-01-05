/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:33:43 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/04 12:14:55 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

char	**check_args(int argc, char **argv)
{
	char	**numbers;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	while (numbers[i])
	{
		while (numbers[i][j])
		{
			if (numbers[i][j] >= '0' && numbers[i][j] <= '9')
				j++;
			else
				errp();
		}
		i++;
		j = 0;
	}
	return (numbers);
}

t_list	*init_stack_a(char **numbers)
{
	t_list	*a;
	t_list	*tmp;
	int		*num;

	a = NULL;
	while (*numbers)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (NULL);
		*num = ft_atoi(*numbers);
		tmp = ft_lstnew(num);
		if (!tmp)
		{
			free(num);
			return (NULL);
		}
		ft_lstadd_back(&a, tmp);
		numbers++;
	}
	return (a);
}

void	errp(void)
{
	ft_printf("ERROR");
	exit(1);
}
