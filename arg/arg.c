/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:33:43 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/08 09:52:55 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	check_args(char **numbers, int argc)
{
	overflow(numbers, argc == 2);
	check_repeat(numbers, argc == 2);
}

void	validate_chars(char **numbers, int split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (numbers[i])
	{
		while (numbers[i][j])
		{
			if ((numbers[i][j] >= '0' && numbers[i][j] <= '9')
				|| (numbers[i][j] == '-' && j == 0 && numbers[i][1])
				|| (numbers[i][j] == '+' && j == 0 && numbers[i][1]))
				j++;
			else
				split_error(numbers, split);
		}
		i++;
		j = 0;
	}
}

char	**split_args(int argc, char **argv)
{
	char	**numbers;
	int		split;

	split = (argc == 2);
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	if (!numbers[0])
		split_error(numbers, split);
	validate_chars(numbers, split);
	check_args(numbers, argc);
	return (numbers);
}
