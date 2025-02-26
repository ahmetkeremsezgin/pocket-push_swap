/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:36:31 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 10:36:38 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->numbers[a->top];
	a->numbers[a->top] = a->numbers[a->top - 1];
	a->numbers[a->top - 1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->top < 1)
		return ;
	temp = b->numbers[b->top];
	b->numbers[b->top] = b->numbers[b->top - 1];
	b->numbers[b->top - 1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->top >= 1)
	{
		temp = a->numbers[a->top];
		a->numbers[a->top] = a->numbers[a->top - 1];
		a->numbers[a->top - 1] = temp;
	}
	if (b->top >= 1)
	{
		temp = b->numbers[b->top];
		b->numbers[b->top] = b->numbers[b->top - 1];
		b->numbers[b->top - 1] = temp;
	}
	write(1, "ss\n", 3);
}
