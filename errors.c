/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:59:02 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/06 11:59:14 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_error(char **numbers)
{
	free_split(numbers);
	errp();
}

void	split_error(char **numbers, int split)
{
	if (split)
		free_split(numbers);
	errp();
}

void	errp(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}
