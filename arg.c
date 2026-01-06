/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:33:43 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/06 11:33:07 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
			if ((numbers[i][j] >= '0' && numbers[i][j] <= '9')
				|| numbers[i][j] == '-')
				j++;
			else
			{
				free_split(numbers);
				errp();
			}
		}
		i++;
		j = 0;
	}
	return (numbers);
}

void	overflow(char **numbers)
{
	int	len;

	while (numbers)
	{
		len = ft_strlen(*numbers);
		if (**numbers == '-')
		{
			if (len > 11)
				free_error(numbers);
			else if (len == 11 && ft_strncmp(*numbers + 1, "2147483648",
					10) > 0)
				free_error(numbers);
		}
		else
		{
			if (len > 10)
				free_error(numbers);
			else if (len == 10 && ft_strncmp(*numbers, "2147483647", 10) > 0)
				free_error(numbers);
		}
		numbers++;
	}
}

void	init_stack(t_list **a, int argc, char **argv)
{
	char	**numbers;
	t_list	*tmp;
	int		*num;

	numbers = check_args(argc, argv);
	while (*numbers)
	{
		num = malloc(sizeof(int));
		if (!num)
		{
			free_error(numbers);
		}
		overflow(numbers);
		*num = ft_atoi(*numbers);
		tmp = ft_lstnew(num);
		if (!tmp)
		{
			free(num);
			free_error(numbers);
		}
		ft_lstadd_back(a, tmp);
		numbers++;
	}
}

void	free_error(char **numbers)
{
	free_split(numbers);
	errp();
}

void	errp(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}
