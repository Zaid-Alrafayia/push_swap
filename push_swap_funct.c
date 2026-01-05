/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:19:03 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/04 21:50:39 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	print_content(void *content)
{
	int	*num;

	num = (int *)content;
	ft_printf("%d\n", *num);
}

void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*head;

	if (*a == NULL)
		return ;
	head = *a;
	*a = (*a)->next;
	head->next = NULL;
	head->next = *b;
	*b = head;
}
