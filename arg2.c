/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:35:09 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/07 00:36:22 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	overflow(char **numbers, int split)
{
	int		len;
	char	**original;

	original = numbers;
	while (*numbers)
	{
		len = ft_strlen(*numbers);
		if (**numbers == '-')
		{
			if (len > 11)
				split_error(original, split);
			else if (len == 11 && ft_strncmp(*numbers + 1, "2147483648",
					10) > 0)
				split_error(original, split);
		}
		else
		{
			if (len > 10)
				split_error(original, split);
			else if (len == 10 && ft_strncmp(*numbers, "2147483647", 10) > 0)
				split_error(original, split);
		}
		numbers++;
	}
}

void	check_repeat(char **numbers, int split)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				split_error(numbers, split);
			j++;
		}
		i++;
	}
}

void	add_to_stack(t_list **a, char **numbers, char **original, int split)
{
	t_list	*tmp;
	int		*num;

	num = malloc(sizeof(int));
	if (!num)
	{
		ft_lstclear(a, free);
		split_error(original, split);
	}
	*num = ft_atoi(*numbers);
	tmp = ft_lstnew(num);
	if (!tmp)
	{
		free(num);
		ft_lstclear(a, free);
		split_error(original, split);
	}
	ft_lstadd_back(a, tmp);
}

void	init_stack(t_list **a, int argc, char **argv)
{
	char	**numbers;
	char	**original;
	int		split;

	split = (argc == 2);
	numbers = split_args(argc, argv);
	original = numbers;
	while (*numbers)
	{
		add_to_stack(a, numbers, original, split);
		numbers++;
	}
	if (split)
		free_split(original);
}
